#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> nextGreat(vector<int> &arr, int n)
{
    stack <int> s;
    vector<int> ans;

    ans.push_back(-1);
    for (int i=n-1;i>=0;i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector <int> arr = {1,2,4,3};
    int n = arr.size();
    vector<int> ans = nextGreat(arr, n);
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}