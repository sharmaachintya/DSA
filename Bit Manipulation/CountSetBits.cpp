#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int count = 0;
    while (n > 0)    
    {
        if (n & 1)
        {
            count++;
        }
        //n = n / 2;
        n = n >> 1;
    }
    cout<<count<<endl;
}