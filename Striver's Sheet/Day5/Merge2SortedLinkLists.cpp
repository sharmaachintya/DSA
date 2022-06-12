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

Node* solve(Node* head1, Node* head2)
{
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }
    Node* curr1 = head1;
    Node* next1 = curr1->next;
    Node* curr2 = head2;
    Node* next2 = curr2->next;
    while (next1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data && next1->data >= curr2->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = curr1->next;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

Node* mergeList(Node* &head1, Node* &head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->data >= head2->data)
    {
        return solve(head1, head2);
    }
    else
    {
        return solve(head2, head1);
    }
}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(tail1,head1, 1);
    insertAtTail(tail1,head1, 3);
    insertAtTail(tail1,head1, 5);
    insertAtTail(tail2,head2, 2);
    insertAtTail(tail2,head2, 4);
    insertAtTail(tail2,head2, 5);

    print(head1); 
    print(head2);  

    Node* ans = mergeList(head1, head2);
    print(ans); 
}