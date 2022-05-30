#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> nums = {1,1,1,3,3,2,2,2};
    int c1 = 0;
    int c2 = 0;
    int num1 = -1;
    int num2 = -1;
    int n = nums.size();
    for (int i=0;i<n;i++)
    {
        if (nums[i] == num1)
        {
            c1++;
        }
        else if (nums[i] == num2)
        {
            c2++;
        }
        else if (c1 == 0)
        {
            num1 = nums[i];
            c1 = 1;
        }
        else if (c2 == 0)
        {
            num2 = nums[i];
            c2 = 1;
        }
        else
        {
            c1--;
            c2--;
        }
    }
    vector <int> ans;
    int count1 = 0;
    int count2 = 0;
    for (int i=0;i<n;i++)
    {
        if (nums[i] == num1)
        {
            count1++;
        }
        else if (nums[i] == num2)
        {
            count2++;
        }
    }
    if (count1 > n/3)
    {
        ans.push_back(num1);
    }
    if (count2 > n/3)
    {
        ans.push_back(num2);
    }
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}