#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool validS(vector<vector<char>> &board)
{
    int R = board.size();
    int C = board[0].size();
    unordered_map <char,int> rows[9];
    unordered_map <char,int> columns[9];
    unordered_map <char,int> boxes[9];
    
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            char ch = board[i][j]; 
            if (ch!= '.' && (rows[i][ch]++ > 0 || (columns[j][ch])++ > 0 || (boxes[i/3*3+j/3][ch])++ > 0))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    bool res;
    vector<vector<char>> board =  {{'8','3','.','.','7','.','.','.','.'}
                                  ,{'6','.','.','1','9','5','.','.','.'}
                                  ,{'.','9','8','.','.','.','.','6','.'}
                                  ,{'8','.','.','.','6','.','.','.','3'}
                                  ,{'4','.','.','8','.','3','.','.','1'}
                                  ,{'7','.','.','.','2','.','.','.','6'}
                                  ,{'.','6','.','.','.','.','2','8','.'}
                                  ,{'.','.','.','4','1','9','.','.','5'}
                                  ,{'.','.','.','.','8','.','.','7','9'}};

    res = validS(board);
    cout<<res;
}