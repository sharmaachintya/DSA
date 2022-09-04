#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    
    int m1[256] = {0};
    int m2[256] = {0};

    for (int i=0;i<str1.length();i++)
    {
        if (!m1[str1[i]] && !m2[str2[i]])
        {
            m1[str1[i]] = str2[i];
            m2[str2[i]] = str1[i];
        }
        else if (m1[str1[i]] != str2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1 = "aab";
    string str2 = "xxy";
    cout<<isIsomorphic(str1, str2);    
}