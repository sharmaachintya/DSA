#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}


bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // Check for left 
    while(y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;
    // Upper left diagonal
    while(x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;
    // Lower left diagonal
    while(x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x++;
        y--;
    }
    return true;
}

void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    // Base Case
    if (col == n)
    {
        addSolution(board,ans,n);
        return;
    }

    // Solve 1 Case
    for (int row=0;row<n;row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col+1, board, ans, n);

            // BackTrack
            board[row][col] = 0;
        }
    }

}

vector<vector<int>> nQueen (int n)
{
    vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0, board, ans, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueen(n);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}