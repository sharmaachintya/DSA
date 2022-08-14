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

Node* middleOfLL(Node* head)
{
    if (head == NULL)
    {
        return head;
    }
    int len = 0;                     
    Node* temp = head;
    while (temp != NULL)            // Finding length of the linked list
    {
        len++;
        temp = temp->next;
    }
    int mid = (len / 2 + 1);
    int count = 1;
    while (count < mid)            // Traverese Linked list till it's middle 
    {
        head = head->next;
        count++;
    }
    return head;
}

int main()
{

}