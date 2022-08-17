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

Node* detectCycle(Node* head)           // FLOYD CYCLE DETETCION
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
        {
            return slow;
        }
    }
    return NULL;
}

Node* getStartingPoint(Node* head)
{
    if (head == NULL)
        return NULL;
    
    Node* slow = head;
    Node* intersection = detectCycle(head);
    if (intersection == NULL)
        return NULL;

    while (intersection != slow)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node* removeCycle(Node* head)
{
    if (head == NULL)
        return head;
    
    Node* startingPoint = getStartingPoint(head);
    Node* temp = startingPoint->next;
    if (startingPoint == NULL)
        return head;
    
    while (temp->next != startingPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

int main()
{
    
}