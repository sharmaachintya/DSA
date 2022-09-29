#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> arr)
{
    set<int> hashSet;
    for(int num : arr)
        hashSet.insert(num);
    
    int longestStreak = 0;
    for (int num : arr)
    {
        if (!hashSet.count(num - 1))
        {
            int currNum = num;
            int currStreak = 1;
            while (hashSet.count(currNum + 1))
            {
                currNum += 1;
                currStreak += 1;
            }
            longestStreak = max(longestStreak, currStreak);
        }
    }
    return longestStreak;
}

int main()
{
    vector<int> arr = {100,4,200,1,3,2};
    cout<<longestConsecutive(arr);    
}