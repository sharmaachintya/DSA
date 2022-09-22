#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    // Transposing the Matrix
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    // Reverse all the rows
    for (int i=0;i<n;i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    rotateMatrix(mat);
    int n = mat.size();
    int m = mat[0].size();
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}