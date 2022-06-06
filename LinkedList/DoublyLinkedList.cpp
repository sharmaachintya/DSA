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

        //Deconstructor
        ~Node()
        {
            int val = this->data;
            if (next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout<<"Memory Freed for Node with data "<<val<<endl;
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

void insertAtHead(Node* &head, Node* &tail, int d)   // Insertion at Head
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d)  // Insertion at Tail
{
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail,int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    else
    {
        Node* temp = head;           // temp is the node which is one node behind the node which is going to get add
        int cnt = 1;
        while(cnt < position - 1)
        {
            temp = temp->next;
            cnt++;
        }
        
        if (temp->next == NULL)
        {
            insertAtTail(tail, head, d);
            return;
        }
        Node* nodeToInsert = new Node(d);

        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    if (position == 1)
    {
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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
    //Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail  = NULL;

    //print(head);
    //cout<<getLength(head)<<endl;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(tail, head, 50);
    insertAtPosition(head, tail, 2, 100);
    insertAtPosition(head, tail, 4, 200);
    insertAtTail(tail, head, 450);
    cout<<"Linked List before Deletion: "<<endl;
    print(head);

    deleteNode(head, tail, 2);

    cout<<"Linked List after Deletion: "<<endl;
    print(head);
    
    cout<<" Head : "<<head->data<<endl;
    cout<<" Tail : "<<tail->data;
}