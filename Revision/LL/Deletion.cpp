#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = next;
        }
};

void deleteAtPosition(Node* &head, Node* &tail, int position)
{
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr; 
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteAtValue(Node* &head, int value)
{
    Node* curr = head;
    Node* prev = NULL;

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    
}
