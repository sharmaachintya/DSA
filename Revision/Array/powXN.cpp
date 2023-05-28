#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double solve(double x, int n)
{
    int nn = n;
    double ans = 1.0;
    if (nn < 0)
        nn = nn * -1;
    while (nn > 0)
    {
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            nn = nn / 2;
            x = x * x;
        }
    }
    return ans;
}


int main()
{
    double x = 2.00000;
    int n = 10;
    cout<<solve(x, n);
}