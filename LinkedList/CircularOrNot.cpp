#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }

        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout<<"Memort Freed for Node having value "<<val<<endl;
        }

};

void insertNode(Node* &tail, int element, int d)             // Insertion
{
    //assuming that the element is present in the list
    if (tail == NULL)                                    // Empty List
    {
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else                                                 // Non-Empty list
    {
        Node* curr = tail;
        while (curr->data != element)
        {
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

////////////////////////////////////////////////////

bool circularOrNot(Node* tail)
{
    if (tail == NULL)
    {
        return true;
    }
    Node* temp = tail->next;
    while (temp != NULL && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////

void print(Node* &tail)
{
    if (tail == NULL)
    {
        cout<<"List is Empty..."<<endl;
    }
    else
    {
        Node* temp = tail; 
        do
        {
            cout<<tail->data<<" ";
            tail = tail->next;
        }
        while(tail != temp);
        cout<<endl;
    }
}

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 19);
    insertNode(tail, 7, 70);

    bool ans = circularOrNot(tail);
    cout<<ans;
}