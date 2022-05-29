#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr = {4,3,6,2,1,1};
    int n = arr.size() + 1;
    vector <int> ans;
    vector <int> freq(n);
    for (int i=0;i<arr.size();i++)
    {
        int element = arr[i];
        freq[element] = freq [element] + 1;
    }
    for (int i=1;i<freq.size();i++)
    {
        if (freq[i] > 1)
        {
            ans.push_back(i);
        }
        else if (freq[i] == 0)
        {
            ans.push_back(i);
        }
    }
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}