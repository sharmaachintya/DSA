#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// In Case Z function just make an integer count and increment it, if you'll find the string

int IndexofFirstOccur(string needle, string haystack)
{
    int n = needle.size();
    for (int i=0;i<haystack.size();i++)
    {
        if (haystack.substr(i, n) == needle)
            return i;
    }
    return -1;
}

int main()
{
    string needle = "sad";    
    string haystack = "sadbutsad";
    cout<<IndexofFirstOccur(needle, haystack);
}