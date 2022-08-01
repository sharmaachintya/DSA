#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        return (ch - 'A' + 'a');
    }
}

bool isPallindrome(char str[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <=e)
    {
        while (s < e && !isalnum(str[s]))
        {
            s++;
        }
        while (s < e && !isalnum(str[e]))
        {
            e--;
        }
        if (toLower(str[s]) != toLower(str[e]))
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}

int getLength(char str[])
{
    int count = 0;
    for (int i=0;str[i] != '\0';i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char str [200];
    cout<<"Enter the string: ";
    cin>>str;
    
    int len = getLength(str);
    //cout<<len;
    bool ans = isPallindrome(str, len);
    if (ans)
        cout<<"YES";
    else
        cout<<"NO";
}