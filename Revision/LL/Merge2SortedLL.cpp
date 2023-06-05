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

Node* merge2Sorted(Node* &head1, Node* &head2)
{
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    Node* curr1 = head1;
    Node* next1 = curr1->next;
    Node* curr2 = head2;
    Node* next2 = curr2->next;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = curr1->next;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node* mergeLists(Node* &head1, Node* &head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    if (head1->data <= head2->data)
        return merge2Sorted(head1, head2);
    else
        return merge2Sorted(head2, head1);
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 10);
    insertAtTail(head1, tail1, 20);
    insertAtTail(head1, tail1, 50);
    insertAtTail(head1, tail1, 80);

    insertAtTail(head2, tail2, 60);
    insertAtTail(head2, tail2, 90);
    insertAtTail(head2, tail2, 110);
    insertAtTail(head2, tail2, 120);
    

    printLL(head1);
    cout<<endl;
    printLL(head2);
    cout<<endl;

    Node* ans = mergeLists(head1, head2);
    printLL(ans);
}