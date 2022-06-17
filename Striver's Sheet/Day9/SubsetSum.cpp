#include<iostream>
#include<algorithm>
using namespace std;

void func(int ind, int sum, vector<int> &arr, int n, vector<int> &sumSet)
{
    // Base case
    if (ind == n)
    {
        sumSet.push_back(sum);
        return;
    }

    // Picking the element
    func(ind+1, sum + arr[ind], arr, n, sumSet);

    // Not picking the element
    func(ind+1, sum, arr, n, sumSet);
}

vector<int> subsetSum(vector<int> arr, int n)
{
    vector<int> sumSet;
    func(0, 0, arr, n, sumSet);
    sort(sumSet.begin(), sumSet.end());
    return sumSet;
}

int main()
{
    int n = 3;
    vector<int> arr = {3, 1, 2};

    vector<int> ans  = subsetSum(arr, n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}