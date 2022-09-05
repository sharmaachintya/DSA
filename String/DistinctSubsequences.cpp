#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int distinctSubseq(string str)
{
    int n = str.length();
    vector<int> dp(n+1);
    dp[0] = 1;
    unordered_map<char, int> mp;             // to check the last occurence of character
    for (int i=1;i<=n;i++)
    {
        dp[i] = 2 * dp[i-1];
        char ch = str[i-1];
        if (mp.find(ch) != mp.end())
        {
            int j = mp[ch];
            dp[i] = dp[i] - dp[j - 1];
        }
        mp.insert({ch, i});
    }
    return dp[n];
}

int main()
{
    string str = "gfg";
    cout<<distinctSubseq(str);    
}