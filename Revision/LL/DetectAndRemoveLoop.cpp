#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = tail->next;
    }
}

void printLL(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* floydC(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node* getStartingPoint(Node* head)
{
    if (head = NULL)
        return NULL;

    Node* intersection = floydC(head);
    if (intersection == NULL)
        return NULL;
    
    Node* slow = head;
    while (intersection != slow)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node* removeCycle(Node* &head)
{
    if (head == NULL)
        return head;
    
    Node* start = getStartingPoint(head);
    Node* temp = start->next;
    if (start == NULL)
        return head;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 200);
    Node* loop1 = new Node(50);
    tail->next = loop1;
    loop1->next = head;
    //insertAtHead(head, 50);

    //printLL(head);
    // cout<<endl;

    head = removeCycle(head);

    printLL(head);


}