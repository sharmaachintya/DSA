#include<iostream>
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

Node* reverseLL(Node* &head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void insertAtHead(Node* &head, int d)     // Insertion At Head
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);             // New Node Creation
        temp->next = head;
        head = temp;
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

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;

    insertAtHead(head, 20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,80);
    insertAtHead(head,90);

    cout<<"Before Reversal: "<<endl;
    print(head);

    cout<<"After Rversal :"<<endl;
    head = reverseLL(head);

    print(head);


}