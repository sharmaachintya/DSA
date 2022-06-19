#include<iostream>
#include<vector>
using namespace std;

void solve(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
    // Base Case
    if (ind >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i=ind;i<nums.size();i++)
    {
        swap(nums[ind], nums[i]);
        solve(ind + 1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    solve(0, nums, ans);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
