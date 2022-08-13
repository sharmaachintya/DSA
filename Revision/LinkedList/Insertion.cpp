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
            this->next = NULL;
        }
};

void insertionAtHead(int data, Node* &head, Node* &tail)
{
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp; 
    }
}

void insertAtTail(int data, Node* &tail, Node* &head)
{
    if (tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }
}

void insertionAtPosition(int data, int position, Node* &head, Node* &tail)
{
    if (position == 1)
    {
        insertionAtHead(data, head, tail);
        return;
    }

    int count = 1;
    Node* temp = head;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(data, tail, head);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{  
    Node* head = NULL;
    Node* tail = NULL;

    insertionAtHead(20, head, tail);
    insertionAtHead(30, head, tail);
    insertAtTail(50, tail, head);
    insertionAtPosition(40, 2, head, tail);
    printList(head);
}