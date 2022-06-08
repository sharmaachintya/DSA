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

void insertAtHead(Node* &head, Node* &tail, int d)     // Insertion At Head
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);             // New Node Creation
        temp->next = head;
        head = temp;
    }
}

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

void insertAtPosition(Node* &tail, Node* &head, int position, int d)    // Insertion At Position
{
    if (position == 1)                                     // Condition when wanted to insert at position 1
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while(cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL)                             // Condition for updating tail, when wanted to insert at last position
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtPosition(Node* &head, Node* &tail,int position)    // Deletion based on the Position
{
    if (position == 1)                                          // Deletion of First Node
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else                                                        // Deletion of any Middle Node and Last Node
    {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deletionAtValue(Node* &head,int value)                   // Deletion based on Value
{
    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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
    //Node *node1 = new Node(10);
    //cout<<node1->data<<endl;

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 15);
    insertAtTail(tail, head, 50);
    insertAtTail(tail, head, 90);
    insertAtPosition(tail, head, 2, 20);
    insertAtPosition(tail, head, 1, 8);
    cout<<"LL BEFORE DELETION: "<<endl;
    print(head);

    //deleteAtPosition(head, tail, 5);
    deletionAtValue(head, 20);
    cout<<"LL AFTER DELETION: "<<endl;
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
}