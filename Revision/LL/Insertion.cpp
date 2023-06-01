#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

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
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d)
{
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail->next = temp;
        tail = tail->next;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void printLL(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 15);
    insertAtTail(tail, head, 50);
    insertAtPosition(head, tail, 3, 51);

    printLL(head);
}