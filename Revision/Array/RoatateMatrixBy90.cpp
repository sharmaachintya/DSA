#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void rotateClock(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i=0;i<n;i++)        // Transposing the Matrix
    {
        for (int j=0;j<i;j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i=0;i<n;i++)        // Reversing all the rows of the matrix
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

void rotateAnti(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    for (int i=0;i<n;i++)        // Transposing the Matrix
    {
        for (int j=0;j<i;j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i=0;i<n;i++)        // Reversing all the Columns of the matrix
    {
        int start = 0, end = m - 1;
        while (start < end)
        {
            swap(arr[start][i], arr[end][i]);
            start++;
            end--;
        }
    }
}


int main()
{
    vector<vector<int>> arr = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    rotateAnti(arr);
    rotateClock(arr);    
}