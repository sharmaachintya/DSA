#include<iostream>
#include<stack>
using namespace std;
int main()
{

    // Creation of Stack
    stack <int> s;

    // Push Operation
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(1);

    // Pop Operation
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<"SIZE: "<<s.size()<<endl;

    if (s.empty())
    {
        cout<<"STACK IS EMPTY "<<endl;
    }
    else
    {
        cout<<"STACK IS NOT EMPTY "<<endl;
    }

    cout<<"Top Element: "<<s.top()<<endl;
}
