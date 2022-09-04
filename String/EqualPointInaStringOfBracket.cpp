#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findLength(string s)
{
    if (s.size() == 0)
        return 0;
    int openbrack = 0, closebrack = 0;
    for (int i=0;i<s.size();i++)
    {
        char ch = s[i];
        if (ch == ')')
            openbrack++;
    }
    for (int i=0;i<s.size();i++)
    {
        char ch = s[i];
        if (ch == '(')
            closebrack++;
        else
            openbrack--;
        if (openbrack == closebrack)
            return i+1;
    }
    return openbrack;
}

int main()
{
    string s = "(())))(";    
    cout<<findLength(s);
}