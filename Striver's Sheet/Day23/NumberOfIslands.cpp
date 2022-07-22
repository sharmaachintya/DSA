#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (grid[i][j] == 0)
        return;
    if (vis[i][j] == 0)
    {
        vis[i][j] = 1;
        dfs(i+1, j, vis, grid, n, m);
        dfs(i-1, j, vis, grid, n, m);
        dfs(i, j+1, vis, grid, n, m);
        dfs(i, j-1, vis, grid, n, m);
        dfs(i+1, j+1, vis, grid, n, m);
        dfs(i-1, j-1, vis, grid, n, m);
        dfs(i+1, j-1, vis, grid, n, m);
        dfs(i-1, j+1, vis, grid, n, m);
    }
}

int numberOfIslands(vector<vector<int>> grid, int n, int m)
{
    vector<vector<int>> vis(n, vector<int> (m, 0));
    // for (int i=0;i<n;i++)
    // {
    //     for (int j=0;i<m;i++)
    //     {
    //         vis[i][j] = 0;
    //     }
    // }

    int cnt = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                dfs(i, j, vis, grid, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,0},
                                {0,1,0,0},
                                {0,0,0,1},
                                {1,0,1,1}};

    int n = grid.size();
    int m = grid[0].size();

    cout<<numberOfIslands(grid, n, m);

}