#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    vector<int> arr = {-8,2,3,-6,10};
    vector<int> ans;
    deque<int> dq;
    int k = 2;

    // Processing the first window
    for (int i=0;i<k;i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Storing answer of first k sized window
    if (dq.size() == 0)
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(arr[dq.front()]);
    }

    // Checking for remaing windows

    for (int i=k;i<arr.size();i++)
    {
        // removal 
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }
        
        // addition

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() == 0)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[dq.front()]);
        }
    }

    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}