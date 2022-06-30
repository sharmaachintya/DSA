#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kLargestSub(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<arr.size();i++)
    {
        int sum = 0;
        for (int j=i;j<arr.size();j++)
        {
            sum = sum + arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}


int main()
{
    vector<int> arr = {4,5,-8,6};
    int k = 2;

    cout<<kLargestSub(arr, k)<<endl;
}