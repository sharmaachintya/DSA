#include<iostream>
using namespace std;
class Stack{
    //propertties
    public:
        int *arr;
        int top;
        int size;

        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element)
        {
            if (size - top > 1)
            {
                top++;
                arr[top] = element;
            }
            else
            {
                cout<<"Stack OverFlow"<<endl;
            }
        }
        void pop()
        {
            if (top >= 0)
            {
                top--;
            }
            else
            {
                cout<<"Stack UnderFlow"<<endl;
            }
        }
        int peek()
        {
            if (top >= 0)
            {
                return arr[top];
            }
            else
            {
                cout<<"Stack is Empty"<<endl;
            }
            return 0;
        }
        bool empty()
        {
            if (top == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
};

int main()
{
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);
    


    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();
    //st.pop();

    if (st.empty())
    {
        cout<<"Stack is Empty"<<endl;
    }
    else
    {
        cout<<"Stack is not Empty"<<endl;
    }

    cout<<st.peek()<<endl;
}