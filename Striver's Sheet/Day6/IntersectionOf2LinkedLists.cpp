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

int getLen(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int intersection(Node* &head1, Node* &head2)
{
    int len1 = getLen(head1);
    int len2 = getLen(head2);

    int d = 0;
    Node* ptr1;
    Node* ptr2;
    if (len1 > len2)
    {
        d = len1 - len2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = len2 - len1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 3);
    insertAtTail(tail1, head1, 1);
    insertAtTail(tail1, head1, 2);
    insertAtTail(tail1, head1, 4);

    insertAtTail(tail2, head2, 7);
    insertAtTail(tail2, head2, 3);
    insertAtTail(tail2, head2, 2);
    insertAtTail(tail2, head2, 4);

    print(head1);
    print(head2);

    int ans = intersection(head1 ,head2);
    cout<<ans;
}