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

/////////////////////////////////////////////////////////////////////

// Approach 1 (Works but causes Space Limit Exceeded) {S.C: O(N)}

bool palindrome(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    vector<int> arr;
    Node* temp = head;
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

// Approach 2 {S.C: O(1)}

Node* getMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

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

bool pallindrome2(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node* middle = getMid(head);            // Find Middle 
    Node* temp = middle->next;              // Reverse L.L after the Middle
    middle->next = reverse(temp);
    Node* head1 = head;                     // Compare Both Halves
    Node* head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    temp = middle->next;                   // Again Reversing the Other half. So, that the L.L remains intact
    middle->next = reverse(temp);
    return true;
}


////////////////////////////////////////////////////////////////////

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    insertAtTail(tail, head, 20);
    insertAtTail(tail, head, 10);
    insertAtTail(tail, head, 20);

    print(head);
    bool ans = palindrome(head);
    cout<<ans;
}