#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length() || j == b.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    if (a[i] == b[j])
        ans = 1 + solve(a, b, i+1, j+1 ,dp);
    else
        ans = max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
    
    return ans;
}

int main()
{
    string s = "bbbab";
    string s2 = "bb";
    vector<vector<int>> dp (s.length(), vector<int> (s2.length(), -1));
    cout<<solve(s2, s, 0, 0, dp);
}