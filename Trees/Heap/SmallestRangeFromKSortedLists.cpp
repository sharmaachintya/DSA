#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c)
        {
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b)
        {
            return a->data > b->data;
        }
};

vector<int> smallestRange(vector<vector<int>> &nums, int n, int k)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;

    for (int i=0;i<k;i++)
    {
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    while (!minHeap.empty())
    {
        node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }


        if (temp->col + 1 < n)
        {
            maxi = max(maxi, nums[temp->row][temp->col+1]);
            minHeap.push(new node(nums[temp->row][temp->col+1], temp->row, temp->col + 1));
        }
        else
        {
            break;
        }
    }
    vector<int> ans(2);
    ans[0] = start;
    ans[1] = end;
    return ans;
}

int main()
{
    vector<vector<int>> nums = {{1,10,11},{2,3,20},{5,6,12}};
    int k = 3, n =3;    
    vector<int> ans = smallestRange(nums, n, k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}