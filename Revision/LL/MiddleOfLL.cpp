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

void insertAtHead(Node* &head, int d)
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
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

Node* middleOfLL(Node* &head)
{
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int cnt = 1;
    while (cnt < (len/2 + 1))
    {
        head = head->next;
        cnt++;
    }
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    //insertAtHead(head, 50);

    printLL(head);
    cout<<endl;

    head = middleOfLL(head);

    printLL(head);

}