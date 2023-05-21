#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solveMem(int i, int j, string &A, string &B, vector<vector<int>> &dp)
{
    // Base Case
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    if (A[i-1] == B[j-1])
        return 1 + solveMem(i-1, j-1, A, B, dp);
    
    return dp[i][j] = 0 + max(solveMem(i-1, j, A, B, dp), solveMem(i, j-1, A, B, dp));
}

int main()
{
    string str = "abcd";
    int n = str.length();
    string s = str;
    reverse(str.begin(), str.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    int lenP = solveMem(n, n, s, str, dp);
    cout<<(n - lenP);
}