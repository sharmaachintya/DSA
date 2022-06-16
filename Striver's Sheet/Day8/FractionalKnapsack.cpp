#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;  
};

bool comp(Item a, Item b)
{
    int r1 = a.value / a.weight;
    int r2 = b.value / b.weight;
    return r1 > r2;
}

int fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr+n, comp);

    int currWeight = 0;
    int finalValue = 0;

    for (int i=0;i<n;i++)
    {
        if (currWeight + arr[i].weight <= W)
        {
            currWeight = currWeight + arr[i].weight;
            finalValue = finalValue + arr[i].value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue = finalValue + ((arr[i].value / arr[i].weight) * remain);
            break;
        }
    }
    return finalValue;
}

int main()
{ 
    int W = 50 , n = 3;
    Item arr[3];
    arr[0].value = 60; 
    arr[1].value = 100;
    arr[2].value = 120;
    arr[0].weight = 10;
    arr[1].weight = 20;
    arr[2].weight = 30;
    int ans = fractionalKnapsack(W, arr, n);
    cout<<ans;
}