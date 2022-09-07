#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string res;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        while(i < n && s[i] == ' ')
        {
            i++;
        }
        int j = i + 1;
        while(j < n && s[j] != ' ')
        {
            j++;
        }
        string temp = s.substr(i, j-i);
        if (res.length() == 0)
        {
            res = temp;
        }
        else
        {
            res = temp + " " + res;
        }
        i = j + 1;
    }
    return res;
}

int main()
{
    string s = "Window down hath Bhaar oyeeee";
    cout<<reverseWords(s);    
}