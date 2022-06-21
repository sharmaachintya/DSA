#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<"SIZE: "<<q.size()<<endl;

    cout<<q.front()<<endl;

    q.pop();

    cout<<"SIZE: "<<q.size()<<endl;

    if (q.empty())
    {
        cout<<"EMEPTY"<<endl;
    }
    else
    {
        cout<<"NOT EMPTY"<<endl;
    }

    cout<<q.front()<<endl;
}