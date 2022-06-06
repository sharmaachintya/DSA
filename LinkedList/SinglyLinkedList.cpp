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

void insertAtPosition(Node* &tail, Node* &head, int position, int d)    // Insertion At Position
{
    if (position == 1)                                     // Condition when wanted to insert at position 1
    {
        insertAtHead(head, d);
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
        insertAtTail(tail,d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
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

    insertAtHead(head, 12);
    insertAtHead(head, 15);
    insertAtTail(tail, 50);
    insertAtTail(tail, 90);
    insertAtPosition(tail,head,2,20);
    insertAtPosition(tail,head, 1, 8);

    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
}