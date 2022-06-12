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

void insertAtTail(Node* &tail, Node* &head, int d)      // Insertion At Tail
{
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        tail = tail->next;
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

void deleteNode(Node* &node)
{
    int val = node->next->data;
    node->data = val;
    node->next = node->next->next;
}
    

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    insertAtTail(tail1,head1, 2);
    insertAtTail(tail1,head1, 5);
    insertAtTail(tail1,head1, 8);
    insertAtTail(tail1,head1, 3);
    insertAtTail(tail1,head1, 10);
    
    Node* node = head1->next->next;

    print(head1); 

    deleteNode(node);
    print(head1);


}