#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPattern(string s, string pattern)
{
    vector<string> arr;
    string temp = "";
    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            arr.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
        i++;
    }
    arr.push_back(temp);

    if (arr.size() != pattern.size())
        return false;

    unordered_map<char, string> mp;
    set<string> st;

    for (int i=0;i<pattern.size();i++)
    {
        if (mp.find(pattern[i]) != mp.end())            // already mapped
        {
            if (mp[pattern[i]] != arr[i])
                return false;
        }
        else
        {
            if (st.count(arr[i]) > 0)
                return false;
            mp[pattern[i]] = arr[i];
            st.insert(arr[i]);
        }
    }
    return true;
}

int main()
{
    string s = "dog cat cat dog";    
    string pattern = "abba";
    cout<<isPattern(s, pattern);
}