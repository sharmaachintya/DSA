#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node *next;

        // Constructor
        Node(int data)
        {
            this->data = data;
            this-> next = NULL;
        }
        // Destructor
        ~Node()
        {
            int value  = this->data;
            if(this->next != NULL)              // Memory Free
            {
                delete next;
                this->next = NULL;
            }
            cout<<"Memory Freed for Node with data "<<this->data<<endl;
        }
};

void insertAtTail(Node* &tail, Node* &head, int d)      // Insertion At Tail
{
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = tail->next;
    }
}


void print(Node* &head)                  // L.L Traversal
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* removeDuplicateUnsorted(Node* &head)
{
    if (head == NULL)
        return head;
    
    unordered_set<int> st;
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL)
    {
        if (st.find(curr->data) != st.end())
        {
            prev->next = curr->next;
        }
        else
        {
            st.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 230);
    insertAtTail(tail, head, 90);
    insertAtTail(tail, head, 230);
    insertAtTail(tail, head, 50);

    print(head);
    cout<<endl;

    head = removeDuplicateUnsorted(head);
    print(head);
}