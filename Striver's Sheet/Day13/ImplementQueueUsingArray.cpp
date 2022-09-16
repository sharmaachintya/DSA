#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
        int size;
        int *arr;
        int front;
        int rear;

        Queue(int size)
        {
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void push(int element)
        {
            if (rear == size)
                cout<<"Queue Overflow!";
            else
            {
                arr[rear] = element;
                rear++;
            }
        }   

        void pop()
        {
            if (front == rear)
                cout<<"Queue Underflow!";
            else   
            {
                int ans = arr[front];
                arr[front] = -1;
                front++;
                if (front == rear)
                {
                    front = 0;
                    rear = 0;
                }
                cout<<ans<<endl;
            }
        }

        bool isEmpty()
        {
            if (front == rear)
                return true;
            else
                return false;
        }

        int fronts()
        {
            if (front == rear)
                cout<<"Queue Underflow!";
            else
                return arr[front];
            return 0;
        }
};


int main()
{
    Queue q(10);
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();

    cout<<q.fronts()<<endl;
    cout<<q.isEmpty();

}