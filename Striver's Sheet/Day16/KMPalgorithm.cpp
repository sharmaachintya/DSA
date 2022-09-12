#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool kmpAlgo(string needle, string haystack)
{
    int n = needle.size();
    for (int i=0;i<haystack.size();i++)
    {
        if (haystack.substr(i, n) == needle)
            return true;
    }
    return false;
}

int main()
{
    string needle = "sad";    
    string haystack = "sadbutsad";
    cout<<kmpAlgo(needle, haystack);
}