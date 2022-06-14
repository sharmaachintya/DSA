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
class Stack{
    public:
        Node* head;
        int size;

        Stack()
        {
            head = NULL;
            size = 0;
        }

        void push(int data)
        {
            Node* temp = new Node(data);
            temp->next = head;
            size++;
            head = temp;
        }

        int peek()
        {
            if (head == NULL)
            {
                cout<<"Stack UnderFlow"<<endl;
                return -1;
            }
            else
            {
                return head->data;
            }
        }

        int pop()
        {
            if (head == NULL)
            {
                cout<<"Stack UnderFlow"<<endl;
            }
            int res = head->data;
            head = head->next;
            size--;
            return res;
        }

        bool empty() 
        {
            if(head == NULL)
            {
                true;
            }
            else
            {
                return false;
            }
            return 1;
        }

        int sizes()
        {
            return size;
        }

};

int main()
{
    
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.peek()<<endl;
    cout<<st.sizes()<<endl;

    cout<<st.pop()<<endl;

    cout<<st.sizes()<<endl;
    st.pop();
    st.pop();
    st.pop();
    //st.pop();

    if (st.empty() == true)
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        cout<<"Stack is not Empty"<<endl;
    }


}
