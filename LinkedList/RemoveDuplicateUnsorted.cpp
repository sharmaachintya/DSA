#include<iostream>
#include<unordered_set>
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

/////////////////////////////////////////////////////////////////////

Node* RemoveDuplicate(Node* head)
{
    unordered_set<int> seen;
    if (head == NULL)
    {
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            //delete curr;
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

////////////////////////////////////////////////////////////////////

int main()
{
    Node* node1 = new Node(40);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 40);
    insertAtTail(tail, head, 70);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 30);

    //print(head);
    cout<<head->data<<endl;
    Node* temp;
    temp = RemoveDuplicate(head);
    print(temp);
}