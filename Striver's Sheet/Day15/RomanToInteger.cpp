#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int roman2Int(string s)
{
    unordered_map<char, int> mp{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}};

    int ans = 0;
    for (int i=0;i<s.length();i++)
    {
        if (mp[s[i]] < mp[s[i+1]])
            ans -= mp[s[i]];
        else
            ans += mp[s[i]];
    }
    return ans;
}

int main()
{
    string s = "LVIII";    
    cout<<roman2Int(s);
}