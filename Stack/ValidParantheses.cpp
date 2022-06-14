#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s)
{
    stack <char> st;
    char ch;
    for (int i=0;i<s.length();i++)
    {
        ch = s[i];

        if (ch == '{' || ch == '(' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "(){}[]";
    bool ans = isValid(s);
    cout<<ans;
}