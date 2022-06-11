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

Node* getMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow ->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 50);

    cout<<"Linked List :"<<endl;
    print(head);

    head = getMid(head);
    cout<<"Middle of the Linked List: "<<endl;
    print(head);

    


}