#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> nums1 = {1,2};
    vector <int> nums2 = {3,4};
    double med;
    for (int i=0;i<nums2.size();i++)
    {
        nums1.push_back(nums2[i]);
    }
    sort(nums1.begin(),nums1.end());
    // for (int i=0;i<nums1.size();i++)
    // {
    //     cout<<nums1[i]<<" ";
    // }
    if (nums1.size()%2 == 1)
    {
        int temp = nums1.size()/2;
        med = nums1[temp];
        cout<<med;
    }
    else
    {
        int temp = nums1.size()/2;
        med = (double)(nums1[temp] + nums1[temp-1])/2;
        cout<<med;
    }
}