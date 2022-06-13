#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int i = 0;
    for (int j=0;j<nums.size();j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}
int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int ans = removeDuplicates(nums);
    cout<<ans<<endl;       // Output consists the number of unique elements
}