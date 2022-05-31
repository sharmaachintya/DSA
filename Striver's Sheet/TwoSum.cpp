#include<iostream>
#include<vector>
using namespace std;
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
}