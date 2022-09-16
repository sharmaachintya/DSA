#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        int *arr;
        int size;
        int top;

        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element)
        {
            if (size - top > 1)
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout<<"Stack Overflow!";
            }
        }

        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout<<"Stack Underflow!";
            }
        }

        bool isEmpty()
        {
            if (top == -1)
            {
                return true;
            }
            else
                return false;
        }

        int peek()
        {
            if (top >= 0)
                return arr[top];
            else
                cout<<"Stack Underflow!";
            return 0;
        }
};


int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
}