#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }

};

class compare {
    public:
        bool operator()(Node* a, Node* b)
        {
            return a->data > b->data;
        }
};

Node* mergeKsortedLists(vector<Node *> list)
{
    priority_queue<Node*, vector<Node*> , compare> minHeap;
    int k = list.size();
    for (int i=0;i<k;i++)
    {
        if (list[i] != NULL)
        {
            minHeap.push(list[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (minHeap.size() > 0)
    {
        Node* top = minHeap.top();
        minHeap.pop();

        if (head == NULL)
        {
            head = top;
            tail = top;

            if (tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
        else
        {
            tail->next = top;
            tail = tail->next;

            if (tail->next != NULL)
            {
                minHeap.push(tail->next);
            }
        }
    }
    return head;
}



int main()
{
    cout<<1;
}