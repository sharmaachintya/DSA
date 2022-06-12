#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    vector <int> prices = {3,1,4,8,7,2,5};
    int Min=prices[0], Max=0;
    for (int i=0;i<prices.size();i++)
    {
        Min = min(Min, prices[i]);
        int prof = prices[i] - Min;
        Max = max(Max, prof);
    }
    cout<<Max;
}