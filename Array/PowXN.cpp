#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int powXN(int x, int n, int m)
{
    int ans = 1;
    long long nn = n;
    long long xx = x;
    if (nn < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            ans = (ans * xx) % m;
            nn = nn - 1;
        }
        else
        {
            xx = (xx) * (xx) % m;
            nn = nn / 2;
        }
    }
    return ans;
}

int main()
{
    int x = 3;
    int n = 1;
    int m = 2; 
    cout<<powXN(x, n, m);
}