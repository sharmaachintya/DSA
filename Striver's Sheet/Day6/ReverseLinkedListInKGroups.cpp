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

Node* reverseList(Node* head1, int k)            // RECURSIVE APPROACH
{
    Node* temp = head1;
    for (int i=0;i<k;i++)
    {
        if (temp == NULL)
        {
            return head1;
        }
        temp = temp->next;
    }
    Node* curr = head1;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if (next != NULL)
    {
        head1->next = reverseList(next, k);
    }
    return prev;
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
    
    cout<<"LINKED LIST BEFORE REVERSAL: "<<endl;
    print(head1);

    int k = 2;
    head1 = reverseList(head1, k);

    cout<<"LINKED LIST AFTER REVERSAL IN K-GROUPS: "<<endl;
    print(head1);
}