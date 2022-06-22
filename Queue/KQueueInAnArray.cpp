#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class KQueue{
    public:
        int* arr;
        int n;
        int k;
        int* front;
        int* rear;
        int* next;
        int freespot;

        KQueue(int n, int k)
        {
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for (int i=0;i<k;i++)
            {
                front[i] = -1;
                rear[i] = -1;
            }
            next = new int[n];
            for (int i=0;i<n;i++)
            {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freespot = 0;
        }

        void enqueue(int data, int qn)
        {
            // check for overflow
            if (freespot == -1)
            {
                cout<<"No empty space available"<<endl;
                return;
            }

            // Find first free index;
            int ind = freespot;

            // Update freespot
            freespot = next[ind];

            // Check whether first element
            if (front[qn - 1] == -1)
            {
                front[qn - 1] = ind;
            }
            else
            {
                next[rear[qn - 1]] = ind;   // Link new element to the prev element
            }

            // Update next
            next[ind] = -1;

            // Update rear
            rear[qn - 1] = ind;

            // Push element
            arr[ind] = data;
        }

        int dequeue(int qn)
        {
            // Check underflow
            if (front[qn - 1] == -1 )
            {
                cout<<"Queue is Empty"<<endl;
                return -1;
            }

            // Find ind to pop
            int ind = front[qn - 1];

            // incrementing front 
            front[qn - 1] = next[ind];

            // Mange freespot
            next[ind] = freespot;
            freespot = ind;
            return arr[ind];
        }

};

int main()
{
    KQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;

}