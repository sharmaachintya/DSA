#include<iostream>
#include<vector>
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

bool palindrome(Node* head)
{
    if (head == NULL || head->next == NULL)
        {
            return true;
        }
    Node* temp = head;
    vector <int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int start = 0;
    int end = arr.size()-1;
    while (start <= end)
    {
        if (arr[start] == arr[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);

    print(head);
    bool ans = palindrome(head);
    cout<<ans;
}