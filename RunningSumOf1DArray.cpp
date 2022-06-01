#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> nums = {1,2,3,4};
    for (int i=0;i<nums.size();i++)
    {
        if (i > 0)
        {
            nums[i] = nums[i] + nums[i-1];
        }
    }
    for (int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
}