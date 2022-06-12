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

int getLength(Node* head)
{
    Node* temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* removeNode(Node* head, int pos)
{
    if (pos == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        for (int i=1;i<pos;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    return head;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int n = 5;

    insertAtTail(tail,head, 1);
    insertAtTail(tail,head, 3);
    insertAtTail(tail,head, 4);
    insertAtTail(tail,head, 7);
    insertAtTail(tail,head, 8);

    //cout<<head->data<<" "<<tail->data<<endl;
    print(head);

    int length = getLength(head);
    int pos = length - n + 1;
    //cout<<pos<<endl;
    
    head = removeNode(head, pos);

    print(head); 
}