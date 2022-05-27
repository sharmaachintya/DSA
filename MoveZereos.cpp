#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr = {1,0,0,4,0,2};
    vector <int> ans;
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        if (arr[i] != 0)
        {
            ans.push_back(arr[i]);
        }
    }
    int size = n - ans.size();
    for (int i=0;i<size;i++)
    {
        ans.push_back(0);
    }
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}
