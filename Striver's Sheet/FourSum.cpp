#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if(nums.empty())
    {
        return res;
    }
    sort (nums.begin(),nums.end());
    for (int i=0;i<nums.size();i++)
    {
        for (int j=i+1;j<nums.size();j++)
        {
            int target_2 = target - nums[j] - nums[i];
            int left = j+1;
            int right = nums.size()-1;
            while (left < right)
            {
                int two_sum = nums[left] + nums[right];
                if (two_sum < target_2)
                {
                    left++;
                }
                else if (two_sum > target_2)
                {
                    right--;
                }
                else
                {
                    vector<int> quadruplet(4,0);
                    quadruplet[0]=nums[i];
                    quadruplet[1]=nums[j];
                    quadruplet[2]=nums[left];
                    quadruplet[3]=nums[right];
                    res.push_back(quadruplet);
                    while (left < right && nums[left] == quadruplet[2])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == quadruplet[3])
                    {
                        --right;
                    }
                }
                while (j+1 < nums.size() && nums[j+1] == nums[j])
                {
                    ++j;
                }
                while (i+1 < nums.size() && nums[i+1] == nums[i] )
                {
                    ++i;
                }
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> res;
    vector <int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    res = fourSum(nums, target);
    for (int i=0;i<res.size();i++)
    {
        for (int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
}