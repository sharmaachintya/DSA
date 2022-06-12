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

Node* add(Node* head1, Node* head2)
{
    int carry = 0;
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int val1 = 0;
        if (head1 != NULL)
        {
            val1 = head1->data;
        }
        int val2 = 0;
        if (head2 != NULL)
        {
            val2 = head2->data;
        }
        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insertAtTail(ansTail, ansHead, digit);
        carry = sum / 10;
        if (head1 != NULL)
        {
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            head2 = head2->next;
        }
    }
    return ansHead;
}

Node* add2Lists(Node* head1, Node* head2)
{
    Node* ans = add(head1, head2);
    return ans;

}

int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail2,head2, 9);
    insertAtTail(tail2,head2, 9);
    insertAtTail(tail2,head2, 9);
    insertAtTail(tail2,head2, 9);

    print(head1); 
    print(head2);  

    Node* ans = add2Lists(head1, head2);
    print(ans);

}