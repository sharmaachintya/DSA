#include<iostream>
#include<vector>
using namespace std;

void solve(int ind, int target, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    // Base Case
    if (ind == nums.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    // Picing the Element

    if (nums[ind] <= target)
    {
        ds.push_back(nums[ind]);
        solve(ind, target - nums[ind], nums, ds, ans);
        ds.pop_back();
    }

    // Not Picking the Element

    solve(ind + 1, target, nums, ds, ans);
}

int main()
{
    vector<int> nums = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, target, nums, ds, ans);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}