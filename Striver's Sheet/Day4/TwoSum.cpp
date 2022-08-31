#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    unordered_map<int, int> mpp;
    vector<int> ans;
    if (nums.empty())
        return ans;

    for (int i=0;i<nums.size();i++)
    {
        if (mpp.find(target - nums[i]) != mpp.end())
        {
            ans.push_back(mpp[target-nums[i]]);
            ans.push_back(i);
        }
        mpp[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector <int> nums = {2, 7, 11, 15};
    int target;
    cout<<"Enter the Target Value: ";
    cin>>target;
    vector <int> ans;
    for (int i=0;i<nums.size();i++)
    {
        for (int j=i+1;j<nums.size();j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    vector<int> res = twoSum(nums, target);
    for (auto i : res)
    {
        cout<<i<<" ";
    }
}