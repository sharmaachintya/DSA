#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && arr[newx][newy] == 1 && visited[newx][newy] != 1)
    {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> &visited, vector<string> &ans, string path, int n)
{
    // Base Case
    if (x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    // Have 4 directions to move in
    // D L R U 

    // Down 
    if (isSafe(x+1, y, visited, arr, n))
    {
        visited[x+1][y] = 1;
        solve(x+1, y, arr, visited, ans, path + 'D', n);
        visited[x+1][y] = 0;
    }

    // Left
    if (isSafe(x, y-1, visited, arr, n))
    {
        visited[x][y-1] = 1;
        solve(x, y-1, arr, visited, ans, path + 'L', n);
        visited[x][y-1] = 0;
    }

    // Right
    if (isSafe(x, y+1, visited, arr, n))
    {
        visited[x][y+1] = 1;
        solve(x, y+1, arr, visited, ans, path + 'R', n);
        visited[x][y+1] = 0;
    }

    // Up
    if (isSafe(x-1, y, visited, arr, n))
    {
        visited[x-1][y] = 1;
        solve(x-1, y, arr, visited, ans, path + 'U', n);
        visited[x-1][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> arr, int n)
{
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    vector<string> ans;
    string path = "";

    if (arr[0][0] == 0)
        return ans;
    
    solve(0, 0, arr, visited, ans, path, n);
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