#include<iostream>
#include<stack>
using namespace std;
class MinStack{
    public:
        stack <int> st1;
        stack <int> st2;
        MinStack()
        {

        }
        void push(int data)
        {
            st1.push(data);
            if (st2.empty() || st2.top() >= data)
            {
                st2.push(data);
            }
        }
        void pop()
        {
            st1.pop();
            if (st1.top() == st2.top())
            {
                st2.pop();
            }
        }
        int top()
        {
            return st1.top();
        }
        int getMin()
        {
            return st2.top();
        }

};
int main()
{
    MinStack st1;

    st1.push(20);
    cout<<st1.top();
}