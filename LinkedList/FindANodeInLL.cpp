#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data = data;
            this->next = NULL;
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

int findNode(Node* head, int n)
{
    Node* temp = head;
    if (head == NULL)
    {
        return -1;
    }
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            return count;
        }
        else if (temp->next == NULL)
        {
            if (temp->data == n)
            {
                return count;
            }
            return -1;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(tail, head, 50);
    insertAtTail(tail, head, 60);
    insertAtTail(tail, head, 70);
    insertAtTail(tail, head, 80);

    int n = 70;

    int ans = findNode(head, n);
    cout<<ans;
}
