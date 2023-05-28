#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // Base Case
    if (i == m-1 && j == n-1)
        return 1;
    if (i >= m || j >= n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = solveMem(i+1, j, m, n, dp) + solveMem(i, j+1, m, n, dp); 
}

int main()
{
    int m = 3, n = 2;
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    cout<<solveMem(0, 0, m, n, dp);    
}