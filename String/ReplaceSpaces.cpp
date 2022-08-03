#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string replaceSpace(string &s)
{
    string ans = "";
    for (int i=0;i<s.length();i++)
    {
        if (s[i] == ' ')
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{
    string s = "My name is achi Boi";
    cout<<replaceSpace(s);    
}