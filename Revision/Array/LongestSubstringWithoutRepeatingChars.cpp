#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string str)
{
    set<char> st;
    int start = 0, end = 0;
    int maxLen = INT_MIN;
    while (start < str.length())
    {
        auto it = st.find(str[start]);

        if (it == st.end())
        {
            int len = start - end + 1;
            if (len > maxLen)
                maxLen = len;
            st.insert(str[start]);
            start++;
        }
        else
        {
            st.erase(str[end]);
            end++;
        }
    }
    return maxLen;
}


int main()
{
    string str = "geeksforgeeks";
    cout<<solve(str);    
}