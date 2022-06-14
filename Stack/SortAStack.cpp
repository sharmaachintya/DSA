#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &nums, int num)
{
    // base case
    if (nums.empty() || nums.top() < num)
    {
        nums.push(num);
        return;
    }
    int n = nums.top();
    nums.pop();

    // Recursive Call
    sortedInsert(nums, num);

    nums.push(n);    
}

void sortStack(stack<int> &nums)
{
    if (nums.empty())
    {
        return;
    }
    int num = nums.top();
    nums.pop();

    // Recursive Call
    sortStack(nums);

    sortedInsert(nums , num);
}

int main()
{
    stack <int> nums;

    nums.push(3);
    nums.push(4);
    nums.push(5);
    nums.push(9);
    nums.push(2);


    sortStack(nums);
    while(!nums.empty())
    {
        cout<<nums.top()<<endl;
        nums.pop();
    }

}