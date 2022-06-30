#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
    }

    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost = cost + sum;
        pq.push(sum);
    }
    return cost;
}

int main()
{
    vector<int> arr = {70 ,59, 41, 42, 75}; 

    int ans = minCost(arr);
    cout<<ans;  
}