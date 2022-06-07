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

void insertNode(Node* &tail, int element, int d)
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

void deleteNode(Node* &tail, int value)
{
    if(tail == NULL)
    {
        cout<<"List is empty... Please Check Again."<<endl;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value)
        {
            curr = curr->next;
            prev = prev->next;
        }
        prev->next = curr->next;
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* &tail)
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

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 3);

    print(tail);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 19);
    insertNode(tail, 7, 70);

    cout<<"Liked List Before Deletion: "<<endl;
    print(tail);

    deleteNode(tail, 70);

    cout<<"Liked List After Deletion: "<<endl;
    print(tail);
    cout<<"TAIL: "<<tail->data<<endl;
}