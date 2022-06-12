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

Node* detectCycle(Node* head)         // FLOYD CYCLE DETECTION 
{
    if (head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
         if (slow == fast)
        {
        return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head)
{
    Node* slow = head;
    if (head == NULL)
    {
        return NULL;
    }
    Node* loop = detectCycle(head);
    while (slow != loop)
    {
        slow = slow->next;
        loop = loop->next;
    }
    return slow;
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

    print(head1);

    tail1->next = head1->next;                // CREATED A MANUAL CYCLE TO CHECK OUTPUT

    head1 = getStartingNode(head1);
    cout<<"STARTING POINT OF LOOP OF THE LINKED LIST IS: "<<head1->data<<endl;
    

    //print(head1);
    
}