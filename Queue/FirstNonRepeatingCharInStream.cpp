#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string firstNonRep(string s)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for (int i=0;i<s.length();i++)
    {
        char ch = s[i];

        count[ch]++;

        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)      // Repeeating Character
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front()); // Non Repeating Character
                break;
            }  
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}


int main()
{
    string s = "aabc";
    string ans = firstNonRep(s);
    cout<<ans;
}