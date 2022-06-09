#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int d)
        {
            this->data = d;
            this->next = NULL;
        }

        ~Node()
        {
            int val = this->data;
            if(this->next != NULL)
            {
                delete next;
                next = NULL;
            }
            cout<<"Memort Freed for Node having value "<<val<<endl;
        }

};

void insertNode(Node* &tail, int element, int d)             // Insertion
{
    //assuming that the element is present in the list
    if (tail == NULL)                                    // Empty List
    {
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else                                                 // Non-Empty list
    {
        Node* curr = tail;
        while (curr->data != element)
        {
            curr=curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

////////////////////////////////////////////////////

// APPROACH 1 {USING MAP}

bool detectLoop(Node* tail)
{
    if (tail == NULL)
    {
        return false;
    }
    map <Node*, bool> visited;
    Node* temp = tail;
    while (temp != NULL)
    {
        if(visited[temp] == true)
        {
            cout<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}



// APPROACH 2 {USING FLOYD CYCLE DETECTION}

bool floydDetectLoop(Node* tail)
{
    if (tail == NULL)
    {
        return false;
    }
    Node* slow = tail;
    Node* fast = tail;

    while(slow != NULL && fast != NULL )
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            cout<<slow->data<<endl;
            return true;
        }
    }
    return false;
}

////////////////////////////////////////////////////

void print(Node* &tail)
{
    if (tail == NULL)
    {
        cout<<"List is Empty..."<<endl;
    }
    else
    {
        Node* temp = tail; 
        do
        {
            cout<<tail->data<<" ";
            tail = tail->next;
        }
        while(tail != temp);
        cout<<endl;
    }
}

int main()
{
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 19);
    insertNode(tail, 7, 70);

    //bool ans = detectLoop(tail);
    bool ans = floydDetectLoop(tail);
    cout<<ans;
}