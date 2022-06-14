#include<iostream>
#include<stack>
using namespace std;


void insertAtBot(stack<int> &nums, int element)
{
    // Base case
    if(nums.empty())
    {
        nums.push(element);
        return;
    }
    int num = nums.top();
    nums.pop();

    insertAtBot(nums, element);

    nums.push(num);
    
}

void reverseStack(stack<int> &nums)
{
    if (nums.empty())
    {
        return;
    }
    int num = nums.top();
    nums.pop();

    reverseStack(nums);

    insertAtBot(nums ,num);

}

int main()
{
    stack <int> nums;

    nums.push(3);
    nums.push(4);
    nums.push(5);
    nums.push(9);
    nums.push(2);


    reverseStack(nums);
    while(!nums.empty())
    {
        cout<<nums.top()<<endl;
        nums.pop();
    }

}