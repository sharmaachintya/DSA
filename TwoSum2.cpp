#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    int target = 8;
    int start = 0;
    vector <int> res;
    int end = nums.size()-1;
    while (start < end)
    {
        if (nums[start]+nums[end] > target)
        {
            end--;
        }
        else if (nums[start]+nums[end] < target)
        {
            start++;
        }
        else
        {
            vector<int> ans{start+1, end+1};
            res = ans;
        }
    }
    for (int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
}