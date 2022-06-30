#include<iostream>
#include<queue>
using namespace std;

int kSmallestElement(vector<int> arr, int k)
{
    priority_queue<int> pq;

    for (int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }

    for (int i=k;i<arr.size();i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {7,10,4,20,15};
    int k = 2;
    cout<<kSmallestElement(arr, k)<<endl;
}