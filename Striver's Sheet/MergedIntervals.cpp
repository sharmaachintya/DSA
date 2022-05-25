#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector <int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector <int>> mergedIntervals;
    if (intervals.size() == 0)
    {
        cout<<"["<<0<<","<<0<<"]";
    }
    sort(intervals.begin(),intervals.end());
    vector <int> temp = intervals[0];
    for (auto it : intervals)
    {
        if (it[0] <= temp[1])
        {
            temp[1] = max(it[1], temp[1]);
        }
        else
        {
            mergedIntervals.push_back(temp);
            temp = it;
        }
    }
    mergedIntervals.push_back(temp);
    for (int i=0;i<mergedIntervals.size();i++)
    {
        for (int j=0;j<mergedIntervals.size();j++)
        {
            cout<<mergedIntervals[i][j]<<" ";
        }
    }
}
