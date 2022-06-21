#include<iostream>
using namespace std;
class CircularQueue{
    public:
        int size;
        int* arr;
        int front;
        int rear;

        CircularQueue(int n)
        {
            size = n;
            arr = new int[n];
            front = -1;
            rear = -1;
        }

        bool enequeue(int data)
        {
            if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            {
                return false;
            }
            if (front == -1)
            {
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
            return true;
        }

        int dequeue()
        {
            if (front == -1)
            {
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if (front == rear)
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
};

int main()
{
    CircularQueue q(5);
    q.enequeue(10);
    q.enequeue(20);
    q.enequeue(30);
    q.enequeue(40);
    q.enequeue(50);

    cout<<q.dequeue()<<endl;


}