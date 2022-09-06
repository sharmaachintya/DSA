#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthSub(string str)
{
    int maxLen = 0;
    int start = 0, end = 0;
    set<char> st;

    while (start < str.length())
    {
        auto it = st.find(str[start]);

        if (it == st.end())                       // Unique char
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
    cout<<lengthSub(str);
}