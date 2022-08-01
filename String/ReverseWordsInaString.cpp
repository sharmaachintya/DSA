#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string revWords(string s)
{
    int i = 0;                            // Beginning of string
    int n = s.length();
    string result;

    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        int j = i + 1;
        while (j < n && s[j] != ' ')
        {
            j++;
        }
        string sub = s.substr(i, j-i);
        if (result.length() == 0)              // First word
        {
            result = sub;
        }
        else
        {
            result = sub + " " + result;
        }
        i = j + 1;
    }
    return result;
}

int main()
{
    string s = " Achi Bawa Kese Ho ? ";
    cout<<"Words after reversing in the String are: "<<revWords(s);
}