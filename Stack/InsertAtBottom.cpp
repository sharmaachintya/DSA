#include<iostream>
#include<stack>
using namespace std;

void insertAtBot(stack<int> &nums, int n)
{
    stack<int> temp;
    while(!nums.empty())
    {
        temp.push(nums.top());
        nums.pop();
    }
    nums.push(n);
    while(!temp.empty())
    {
        nums.push(temp.top());
        temp.pop();
    }
}

int main()
{
    stack <int> nums;

    nums.push(3);
    nums.push(4);
    nums.push(5);
    nums.push(9);
    nums.push(2);

    int n;
    cout<<"Enter the Element: ";
    cin>>n;

    insertAtBot(nums, n);

    while(!nums.empty())
    {
        cout<<nums.top()<<endl;
        nums.pop();
    }
}