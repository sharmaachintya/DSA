#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int numRows = 5;
    vector<vector<int>> r(numRows);
    for (int i=0;i<numRows;i++)
    {
        r[i].resize(i+1);
        r[i][0]=r[i][i]=1;
        for (int j=1;j<i;j++)
        {
            r[i][j]=r[i-1][j-1] + r[i-1][j];
        }
    }
    for (int i=0;i<r.size();i++)
    {
        for (int j=0;j<r[0].size();j++)
        {
            cout<<r[i][j]<<" ";
        }
    }
}