#include<iostream>
#include<algorithm>
using namespace std;

void solve(int ind, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans)
{
    ans.push_back(ds);                                   // Initial push for empty list
    for (int i=ind;i<nums.size();i++)
    {
        if (i != ind && nums[i] == nums[i-1])            // Condition to avoid indexes containing duplicates
        {
            continue;
        }
        ds.push_back(nums[i]);
        solve(i+1, ds, nums, ans);
        ds.pop_back();
    }
} 


int main()
{
    vector<int> nums = {1,2,2};
    vector<int> ds;
    vector<vector<int>> ans;
    solve(0, ds, nums , ans); 
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
    }

}