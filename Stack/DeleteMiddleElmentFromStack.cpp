#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &nums, int count, int N)
{
    //base case
    if (count == N/2);
    {
        nums.pop();
        return;
    }
    int num = nums.top();
    nums.pop();

    // Recursive call
    solve(nums, count+1, N);
    nums.push(num);
}

void deleteMiddle(stack<int> &nums, int N)
{
    int count = 0;
    solve(nums, count , N);
}

int main()
{
    stack <int> nums;

    nums.push(3);
    nums.push(4);
    nums.push(5);
    nums.push(9);
    nums.push(2);

    int N = nums.size();
    deleteMiddle(nums, N);
    while(!nums.empty())
    {
        cout<<nums.top()<<endl;
        nums.pop();
    }

}