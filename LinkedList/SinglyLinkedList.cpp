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
};

void insertAtHead(Node* &head, int d)     // Insertion At Head
{
    Node *temp = new Node(d);             // New Node Creation
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int d)      // Insertion At Tail
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
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
    Node *node1 = new Node(10);
    //cout<<node1->data<<endl;

    Node *head = node1;
    Node *tail = node1;
    print(head);

    // insertAtHead(head, 12);
    // insertAtHead(head, 15);
    insertAtTail(tail, 50);
    insertAtTail(tail, 90);

    print(head);
}