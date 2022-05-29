#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> reshape(vector<vector<int>> &arr, int r, int c)
{
    vector<vector<int>> ans(r,vector<int>(c));
    if (arr.size()*arr[0].size() != r*c)
    {
        return arr;
    }
    int row = 0;
    int col = 0;
    for (int i=0;i<arr.size();i++)
    {
        for (int j=0;j<arr[0].size();j++)
        {
            ans[row][col] = arr[i][j];
            col++;
            if (col == c)
            {
                row++;
                col=0;
            }
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1,2},{3,4}};
    vector<vector<int>> result ;
    int r = 1;
    int c = 4;
    result = reshape(arr, r, c);
    for (int i=0;i<result.size();i++)
    {
        for (int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}