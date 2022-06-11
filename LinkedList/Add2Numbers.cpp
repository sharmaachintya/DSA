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

///////////////////////////////////////////////////////////////////

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* add(Node* first, Node* second)
{
    int carry = 0;
    Node* anshead = NULL;
    Node* ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAtTail(ansTail, anshead, digit);
        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        
        if (second != NULL)
            second = second->next;
    }
    return anshead;
}


Node* add2Lists(Node* head1, Node* head2)
{
    Node* first = reverse(head1);
    Node* second = reverse(head2);

    Node* ans = add(first, second);
    ans = reverse(ans);
    return ans;
}


//////////////////////////////////////////////////////////////////


int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(tail1,head1, 4);
    insertAtTail(tail1,head1, 5);
    insertAtTail(tail2,head2, 3);
    insertAtTail(tail2,head2, 4);
    insertAtTail(tail2,head2, 5);

    print(head1); 
    print(head2);  

    Node* ans = add2Lists(head1, head2);
    print(ans);

}