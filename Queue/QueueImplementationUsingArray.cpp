#include<iostream>
using namespace std;
class Queue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        // Constructor
        Queue()
        {
            size = 10000;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void enqueue(int data)     // Push operation
        {
            if (rear == size)
            {
                cout<<"Queue is Full "<<endl;
            }
            else
            {
                arr[rear] = data;
                rear++;
            }
        }

        int dequeue()            // Pop operation
        {
            if (front == rear)
            {
                return -1;
            }
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
                return ans;
            }
            return -1;
        }

        int fronts()           // Front operation
        {
            if (front == rear)
            {
                return -1;
            }
            else
            {
                return arr[front];
            }
            return -1;
        }

        bool empty()
        {
            if (front == rear)
            {
                return true;
            }
            return false;
        }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout<<q.fronts()<<endl;
    
    cout<<q.dequeue()<<endl;

    cout<<q.fronts()<<endl;

    cout<<q.empty()<<endl;
}