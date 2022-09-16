#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int num)
{
    if (st.empty() || st.top() < num)
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();

    sortedInsert(st, num);

    st.push(n);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    sortStack(st);

    sortedInsert(st, num);
}

int main()
{
    stack<int> st;
    st.push(5);   
    st.push(-2);  
    st.push(9);  
    st.push(-7);  
    st.push(3);

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    sortStack(st);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}