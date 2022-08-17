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

bool circularOrNot(Node* head)
{
    if (head == NULL)
        return true;

    if (head->next == NULL)
        return false;

    Node* temp = head->next;
    while (temp != NULL || temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;
    
    return false;
}

int main()
{

}