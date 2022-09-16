#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isValid(stack<char> st, string str)
{
    for (int i=0;i<str.length();i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            else
            {
                char top = st.top();
                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'))
                    st.pop();
                else
                    return false;
            }
        }
    }
    if (st.empty())
        return true;
    return false;
}

int main()
{
    stack<char> st;
    string str = "[()]{}{[()()]()}";    
    cout<<isValid(st, str);
}