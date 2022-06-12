#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    vector <int> nums = {100,1,40,2,3,4};
    set <int> ans;
    for (int i=0;i<nums.size();i++)
    {
        ans.insert(nums[i]);
    }
    int MaxLength = 0;
    for (int i=0;i<nums.size();i++)
    {
        int num = nums[i];
        if (!ans.count(num-1))
        {
            int currNum = num;
            int currMax = 1;
            while (ans.count(currNum + 1))
            {
                currNum += 1;
                currMax += 1;
            }
            MaxLength = max(MaxLength, currMax);
        }
    }
    cout<<MaxLength;
}