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

Node* sort012(Node* &head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else if (temp->data == 2)
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (count0 != 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 != 0)
        {
            temp->data = 1;
            count1--;
        }
        else if (count2 !=0)
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}



//////////////////////////////////////////////////////////////////


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(tail,head, 0);
    insertAtTail(tail,head, 1);
    insertAtTail(tail,head, 2);
    insertAtTail(tail,head, 0);
    insertAtTail(tail,head, 2);
    insertAtTail(tail,head, 1);

    print(head);    

    head = sort012(head);
    print(head);
}