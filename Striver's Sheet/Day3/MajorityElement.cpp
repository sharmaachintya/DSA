#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums = {3,2,3};
    int count = 0;
    int element = 0;
    for (int i=0;i<nums.size();i++)
    {
        if (count == 0)
        {
            element = nums[i];
        }
        if (element == nums[i])
        {
            count ++;
        }
        else
        {
            count--;
        }
    }
    cout<<element;
}