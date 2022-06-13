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

Node* rotate(Node* head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
    {
        return head;
    }
    Node* curr = head;
    int len = 1;
    while (curr->next != NULL)
    {
        len++;
        curr = curr->next;
    }
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
    {
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
}

int main()
{
    

    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 3);
    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 2);
    insertAtTail(tail1, head1, 4);

    cout<<"LINKED LIST BEFORE ROTATION: "<<endl;
    print(head1);

    int k = 2;
    head1 = rotate(head1, k);

    cout<<"LINKED LIST AFTER ROTATION: "<<endl;
    print(head1);

    
}