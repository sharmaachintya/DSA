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

Node* addLists(Node* &first, Node* &second)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;
        int val2 = 0;
        if (second != NULL)
            val2 = second->data;
        
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        
        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

Node* add2Lists(Node* &head1, Node* &head2)
{
    Node* first = reverse(head1);
    Node* second = reverse(head2);

    Node* ans = addLists(first, second);
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 3);
    insertAtTail(head1, tail1, 4);

    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 0);

    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout<<endl;

    Node* ans = add2Lists(head1, head2);
    printLL(ans);
}