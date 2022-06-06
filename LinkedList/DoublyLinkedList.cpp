#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        // Constructor
        Node(int d)
        {
            this->data = d;
            this->prev = NULL;
            this->next = NULL;
        }

};

int getLength(Node* head)            // Gives Length of the Linked List
{
    int len = 0;
    Node* temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node* &head, int d)   // Insertion at Head
{
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int d)  // Insertion at Tail
{
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void print(Node* &head)                // Traversal of Doubly Linked List
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
    Node* tail  = node1;

    print(head);
    cout<<getLength(head)<<endl;

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtTail(tail, 50);

    print(head);
}