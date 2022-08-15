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

Node* reverseInKGroups(Node* &head, int k)
{
    // Base Case
    Node* temp = head;
    for (int i=0;i<k;i++)
    {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }

    // Step 1: Reverse first k nodes
    int count = 0;
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step 2: Recursive call
    if (forward != NULL) 
    {
        head->next = reverseInKGroups(forward, k);
    }

    // Step 3: Retrun the head of reverse linked list
    return prev;
}

int main()
{
    
}