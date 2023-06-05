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

Node* getMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse(Node* &head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;
    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

bool isPallindrome(Node* head)
{
    if (head == NULL || head->next == NULL)
        return true;
    
    Node* mid = getMid(head);
    Node* temp = mid->next;
    mid->next = reverse(temp);
    Node* head1 = head;
    Node* head2 = mid->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}


int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertAtTail(head1, tail1, 10);
    insertAtTail(head1, tail1, 20);
    insertAtTail(head1, tail1, 50);
    insertAtTail(head1, tail1, 80);
    insertAtTail(head1, tail1, 50);
    insertAtTail(head1, tail1, 20);
    insertAtTail(head1, tail1, 10);

    printLL(head1);
    cout<<endl;

    cout<<isPallindrome(head1);
}