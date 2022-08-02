#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char getMaxOcc(string s)
{
    int arr[26] = {0};  

    for (int i=0;i<s.length();i++)
    {
        char ch = s[i];

        // Assuming that the whole string is in lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    int maxi = -1;
    int index = 0;
    for (int i=0;i<26;i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
            index = i;
        }
    }

    char finalAns = 'a' + index;
    return finalAns;
}

int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;

    char ans = getMaxOcc(s);
    cout<<ans;
}