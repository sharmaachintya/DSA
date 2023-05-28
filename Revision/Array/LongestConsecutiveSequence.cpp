#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &arr)
{
    set<int> st;
    int n = arr.size();
    for (int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }

    int longestStreak = 0;
    for (int i=0;i<n;i++)
    {
        int num = arr[i];
        if (!st.count(num - 1))
        {
            int currNum = num;
            int currStreak = 1;
            while (st.count(currNum + 1))
            {
                currNum++;
                currStreak++;
            }
            longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;
}

int main()
{
    vector<int> arr = {200, 1, 100, 3, 2, 4};    
    cout<<solve(arr);
}