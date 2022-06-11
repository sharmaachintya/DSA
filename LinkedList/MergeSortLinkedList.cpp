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

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}


Node* mergeSort(Node* head)
{
    //base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both left and righ halves
    Node* ans = merge(left, right);
    return ans;
}

//////////////////////////////////////////////////////////////////


int main()
{
    Node* head1 = NULL;
    Node* tail1 = NULL;

   

    insertAtTail(tail1,head1, 1);
    insertAtTail(tail1,head1, 3);
    insertAtTail(tail1,head1, 5);
    insertAtTail(tail1,head1, 9);
    insertAtTail(tail1,head1, 2);
    
    print(head1); 

    head1 = mergeSort(head1);
    print(head1);

    
}