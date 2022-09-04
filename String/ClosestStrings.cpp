#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int closestString(vector<string> &s, string word1, string word2)
{
    if (s.size() == 0)
        return 0;
    
    int w1 = INT_MAX, w2 = INT_MAX;
    int count = INT_MAX;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == word1)
            w1 = i;
        if (s[i] == word2)
            w2 = i;

        if (w1 != INT_MAX || w2 != INT_MAX)
            count = min(count, abs(w1-w2));
    }
    return count;
}

int main()
{
    vector<string> s = {"geeks", "for", "geeksd", "contribute", "practice"};
    string word1 = "geeks";
    string word2 = "contribute";
    cout<<closestString(s, word1, word2);    
}