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

    print(head);
    cout<<getLength(head);
}