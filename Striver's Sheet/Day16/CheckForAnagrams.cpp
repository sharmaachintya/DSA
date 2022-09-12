#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string str1, string str2)
{
    int arr1[26] = {0};
    int arr2[26] = {0};

    for (int i=0;i<str1.length();i++)
    {
        arr1[str1[i] - 'a']++;
    }
    for (int i=0;i<str2.length();i++)
    {
        arr2[str2[i] - 'a']++;
    }

    for (int i=0;i<26;i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }   
    return true;
}

int main()
{
    string str1 = "listen";
    string str2 = "silent";
    cout<<isAnagram(str1, str2);
}