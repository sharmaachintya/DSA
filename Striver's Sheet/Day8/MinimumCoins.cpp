#include<iostream>
#include<algorithm>
using namespace std;

void minimumCoins(int arr[], int V, int n)
{
    vector<int> ans;
    for (int i=n-1;i>=0;i--)
    {
        while (V >= arr[i])
        {
            V = V - arr[i];
            ans.push_back(arr[i]);
        }
    }

    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Number of Coins used: "<<ans.size();
}

int main()
{
    int V = 49;
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;

    minimumCoins(deno, V, n);
}