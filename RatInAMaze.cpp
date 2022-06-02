#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m)
{
    if ( (x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 &&  m[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, int srcx, int srcy, vector<vector<int>> visited, string path )
{
    //base case
    if (srcx == n-1 && srcy == n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[srcx][srcy] = 1;

    // Down
    int newx = srcx+1;
    int newy = srcy;
    if (isSafe(newx, newy, n ,visited, m))
    {
        path.push_back('D');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    // Left
    newx = srcx;
    newy = srcy-1;
    if (isSafe(newx, newy, n ,visited, m))
    {
        path.push_back('L');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Right
    newx = srcx;
    newy = srcy+1;
    if (isSafe(newx, newy, n ,visited, m))
    {
        path.push_back('R');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    //Up
    newx = srcx-1;
    newy = srcy;
    if (isSafe(newx, newy, n ,visited, m))
    {
        path.push_back('U');
        solve(m,n,ans,newx,newy,visited,path);
        path.pop_back();
    }
    visited[srcx][srcy] = 0;
}
int main()
{
    int n = 4;
    vector<vector<int>> m = {{1,0,0,0},
                             {1,1,0,1},
                             {1,1,0,0},
                             {0,1,1,1}};
    vector<string> ans;
    int srcx=0;
    int srcy=0;
    vector<vector<int>> visited = m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            visited[i][j]=0;
        }
    }
    string path = "";
    solve(m,n,ans,srcx,srcy,visited,path);
    sort(ans.begin(),ans.end());
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
}