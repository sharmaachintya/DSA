#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string longestCommonPre(vector<string> str)
{
    string ans = "";
    for (int i=0;i<str[0].length();i++)
    {
        char ch = str[0][i];
        bool isMatch = true;

        for (int j=0;j<str.size();j++)
        {
            if (ch != str[j][i])
            {
                isMatch = false;
                break;
            }
        }
        if (isMatch == false)
            break;
        else
            ans.push_back(ch);
    }
    return ans;
}

int main()
{
    vector<string> str = {"flower","flow","flight"};    
    cout<<longestCommonPre(str);
}