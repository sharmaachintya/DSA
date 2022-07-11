#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double multiply(int mid, int n)
{
    double ans = 1.0;
    for (int i=1;i<=n;i++)
    {
        ans = ans * mid;
    }
    return ans;
}

double getNthRoot(int n, int m)
{
    double low = 1;
    double high = m;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (low + high) /2.0;
        if (multiply(mid, n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}
int main()
{
    int n, m;
    cout<<"Enter N: ";
    cin>>n;
    cout<<"Enter M: ";
    cin>>m;

    cout<<getNthRoot(n, m);
  
}