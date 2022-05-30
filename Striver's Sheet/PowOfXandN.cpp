#include<iostream>
using namespace std;
int main()
{
    int x = 2;
    int n = 10;
    double ans = 1.0;
    int long nn = n;
    if (nn < 0)
    {
        nn = nn * -1;
    }
    while (nn > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * x;
            n = n - 1;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)1.0 / (double)ans;
    }
    cout<<ans<<endl;
}