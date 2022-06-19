#include<iostream>
#include<algorithm>
using namespace std;

void solve(int ind, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
{
    // Base Case
    if (target == 0)
    {
        ans.push_back(ds);
    }
    for (int i=ind;i<nums.size();i++)
    {
        if (i > ind && nums[i] == nums[i-1])   // Not Picking the element
        {
            continue;
        }
        if (nums[i] > target)                 // Only checking if the presnt element is greater than the remaining target
        {
            break;
        }
        ds.push_back(nums[i]);
        solve(i+1, target - nums[i], nums, ans, ds);
        ds.pop_back();
    }
}

int main()
{
    vector<int> nums = {1,1,1,2,2};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    int target = 4;
    solve(0, target, nums, ans, ds);

}