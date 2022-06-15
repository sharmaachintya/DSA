#include<iostream>
#include<stack>
using namespace std;

bool redundantBrack(string &str)
{
    stack <char> st;
    for (int i=0;i<str.length();i++)
    {
        char ch = str[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool ans = true;
                while(st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        ans = false;
                    }
                    st.pop();
                }
                if (ans == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "(a*b(a+b))";
    bool ans = redundantBrack(str);
    cout<<ans;

}