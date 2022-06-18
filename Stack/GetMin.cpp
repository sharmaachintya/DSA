#include<iostream>
#include<stack>
using namespace std;
class GetMin{
    public:
        stack <int> s1;
        stack <int> s2;

        GetMin()
        {
            
        }

        void push(int val)
        {
        s1.push(val);
        if(s2.empty() || s2.top() >= val)
            {
                s2.push(val);
            }
        }

        void pop()
        {
            s1.pop();
            if (s1.top() == s2.top())
            {
                s2.pop();
            }
        }

        int top()
        {
            return s1.top();    
        }

        int getMin()
        {
            return s2.top();
        }
};

int main()
{
    GetMin st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(52);
    cout<<st.top()<<endl;
    cout<<st.getMin()<<endl;
}
