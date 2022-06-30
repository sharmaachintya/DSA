#include<iostream>
#include<queue>
using namespace std;
int main()
{

    // Max Heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Element On Top: "<<pq.top()<<endl;
    pq.pop();

    cout<<"Element On Top: "<<pq.top()<<endl;

    cout<<"Size: "<<pq.size()<<endl;

    if(pq.empty())
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"Not Empty"<<endl;
    }


    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"Element On Top: "<<minHeap.top()<<endl;
    minHeap.pop();

    cout<<"Element On Top: "<<minHeap.top()<<endl;

    cout<<"Size: "<<minHeap.size()<<endl;

    if(minHeap.empty())
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        cout<<"Not Empty"<<endl;
    }
}