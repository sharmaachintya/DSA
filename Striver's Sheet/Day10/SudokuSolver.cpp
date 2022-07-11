#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i=0;i<board.size();i++)
    {
        if (board[row][i] == val)   // Check for Row
            return false;
        if (board[i][col] == val)   // Check for Column
            return false;
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board.size();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (board[i][j] == 0)
            {
                for (int val=1;val<=9;val++)
                {
                    if (isSafe(i, j, board, val))
                    {
                        board[i][j] = val;
                        bool nextSol = solve(board);
                        if (nextSol)
                        {
                            return true;
                        }
                        else
                        {
                            //  Backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveBoard(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> sudoku = {{5,3,0}, {0,7,0}, {0,0,0},
                                  {6,0,0}, {1,9,5}, {0,0,0},
                                  {0,9,8}, {0,0,0}, {0,6,0},

                                  {8,0,0}, {0,6,0}, {0,0,3},
                                  {4,0,0}, {8,0,3}, {0,0,1},
                                  {7,0,0}, {0,2,0}, {0,0,6},

                                  {0,6,0}, {0,0,0}, {2,8,0},
                                  {0,0,0}, {4,1,9}, {0,0,5},
                                  {0,0,0}, {0,8,0}, {0,7,9},};
    
    solveBoard(sudoku);
    for (auto i : sudoku)
    {
        for (auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }


}