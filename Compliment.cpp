#include<iostream>
using namespace std;
int compliment(int num)
{
    int m = num;
    int mask = 0;
    if (num == 0)
    {
        return 1;
    }
    while (m!=0)
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~num) & mask;
    return ans;
    
}
int main()
{
    int res,n;
    cout<<"Enter the Number: ";
    cin>>n;
    res = compliment(n);
    cout<<res;
}