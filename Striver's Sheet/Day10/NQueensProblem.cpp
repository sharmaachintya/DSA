#include<iostream>
#include<algorithm>
using namespace std;

bool isSafe(int row, int col, vector<string> board, int n)
{
    int duprow = row;
    int dupcol = col;

    // Checking upper Diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    // Checking left columns

    row = duprow;
    col = dupcol;

    while (col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        col--;
    }

    // Checking lower diagonals

    row = duprow;
    col = dupcol;

    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}



void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    // Base case
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row=0;row<n;row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';    // Backtracking if wrong solution
        }
    }

}

int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i=0;i<n;i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}