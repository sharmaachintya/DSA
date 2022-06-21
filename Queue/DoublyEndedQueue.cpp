#include<iostream>
using namespace std;
class Dequeue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Dequeue(int n)
        {
            size = n;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool pushFront(int x)
        {
            if (front == 0 && rear == size - 1 || rear == (front - 1) % (size - 1))
            {
                return false;
            }
            else if (front == -1)
            {
                front = rear = 0;
            }
            else if (front == 0 && rear != size - 1)
            {
                front = size - 1;
            }
            else
            {
                front--;
            }
            arr[front] = x;
            return true;
        }

        bool pushBack(int x)
        {
            if (front == 0 && rear == size - 1 || front != 0 && rear == (front - 1) % (size - 1))
            {
                return false;
            }
            else if (front == -1)
            {
                front = rear = 0;
            }
            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = x;
            return true;
        }

        int popFront()
        {
            if (front == -1)
            {
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if (front == rear)    // Only 1 element in Queue
            {
                front = -1;
                rear = -1;
            }
            else if (front == size - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return ans;
        }

        int popBack()
        {
            if (front == -1)
            {
                return -1;
            }
            int ans = arr[rear];
            arr[rear] = -1;
            if (front == rear)
            {
                front = rear = -1;
            }
            else if (rear == 0)
            {
                rear = size - 1;
            }
            else
            {
                rear--;
            }
            return ans;
        }

        int getFront()
        {
            if (isEmpty())
            {
                return -1;
            }
            else
            {
                return arr[front];
            }
        }

        int getRear()
        {   
            if (isEmpty())
            {
                return -1;
            }
            else
            {
                return arr[rear];
            }
        }

        bool isEmpty()
        {
            if (front == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isFull()
        {
            if (front == 0 && rear == size - 1 || front != 0 && rear == (front - 1) % (size - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

int main()
{
    Dequeue q(10);
    q.pushFront(10);
    q.pushBack(20);
    q.pushBack(30);
    q.pushBack(40);
    q.pushBack(50);
    q.pushBack(60);
    q.pushBack(70);
    q.pushBack(80);
    q.pushBack(90);
    q.pushBack(200);


    //q.popFront();


    cout<<q.popBack()<<endl;
    cout<<q.popFront()<<endl;

    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
}