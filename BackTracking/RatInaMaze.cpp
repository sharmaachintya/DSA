#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &arr, vector<vector<bool>> &vis, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && vis[newx][newy] != 1 && arr[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &vis,vector<string> &ans, int n, string path)
{
    // Base Case
    if (x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }


    // Have 4 Moments
    // D , L , R , U

    // Down
    if (isSafe(x+1,y,arr,vis,n))
    {
        vis[x][y] = 1;
        solve(x+1, y, arr, vis, ans, n, path+'D');
        vis[x][y] = 0;
    }

    // Left
    if (isSafe(x,y-1,arr,vis,n))
    {
        vis[x][y] = 1;
        solve(x, y-1, arr, vis, ans, n, path+'L');
        vis[x][y] = 0;
    }

    // Right
    if (isSafe(x,y+1,arr,vis,n))
    {
        vis[x][y] = 1;
        solve(x, y+1, arr, vis, ans, n, path+'R');
        vis[x][y] = 0;
    }

    // Up
    if (isSafe(x-1,y,arr,vis,n))
    {
        vis[x][y] = 1;
        solve(x-1, y, arr, vis, ans, n, path+'U');
        vis[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path = "";
    if (arr[0][0] == 0)
        return ans;

    solve(0,0,arr,visited,ans,n,path);
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,0,0,0},
                               {1,1,0,0},
                               {1,1,0,0},
                               {0,1,1,1}};

    int n = arr.size();

    vector<string> ans = searchMaze(arr, n);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}