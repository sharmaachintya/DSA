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

        Node(int data, Node* head)
        {
            this->data = data;
            this-> next = head;
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
   if (head == NULL)
   {
       return head;
   }
   Node* temp = new Node(0, head);
   Node* prev = temp;
   while (head != NULL)
   {
       if (head->next != NULL && head->data == head->next->data)
       {
           while (head->next != NULL && head->data == head->next->data)
           {
               head = head->next;
           }
           prev->next = head->next;
       }
       else
       {
           prev = prev->next;
       }
       head = head->next;
   }
    return temp->next;
}

////////////////////////////////////////////////////////////////////

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 30);
    insertAtTail(tail, head, 40);

    print(head);
    //cout<<head->data<<endl;
    Node* temp;
    temp = RemoveDuplicate(head);
    print(temp);
}