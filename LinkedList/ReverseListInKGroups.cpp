#include<iostream>
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
};

void insertAtHead(Node* &head, int d)     // Insertion At Head
{
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);             // New Node Creation
        temp->next = head;
        head = temp;
    }
}

////////////////////////////////////////////////////////////////

Node* reverseListK(Node* &head, int k)
{
    // Base Case
    Node* temp = head;
    for (int i=0;i<k;i++)
    {
        if (temp == NULL)
        {
            return head;
        }
        temp = temp->next;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;
    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    if (next != NULL)
    {
        head->next = reverseListK(next, k);
    }
    return prev;
}

///////////////////////////////////////////////////////////////

void print(Node* &head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(5);
    Node* head = node1;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    //insertAtHead(head, 6);

    cout<<"BEFORE K GROUPS REVERSE: "<<endl;
    print(head);

    int k = 3;

    Node* ans = NULL;
    ans = reverseListK(head, k);

    cout<<"AFTER K GROUPS REVERSE: "<<endl;
    print(ans);

}