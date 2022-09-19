#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
        stack<int> input;
        stack<int> output;

        void push(int element)
        {
            input.push(element);
        }

        void pop()
        {
            if(output.empty())
            {
                while(!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
                output.pop();
            }
            else
                output.pop();
        }

        int front()
        {
            if (output.empty())
            {
                while(!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
                return output.top();
            }
            else
                return output.top();
            return 0;
        }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}