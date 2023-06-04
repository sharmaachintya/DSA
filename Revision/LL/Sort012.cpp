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

Node* sort012(Node* &head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else if (temp->data == 2)
            count2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (count0 != 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 != 0)
        {
            temp->data = 1;
            count1--;
        }
        else if (count2 != 0)
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);
    insertAtTail(head, tail, 0);

    printLL(head);
    cout<<endl;

    head = sort012(head);
    printLL(head);
}