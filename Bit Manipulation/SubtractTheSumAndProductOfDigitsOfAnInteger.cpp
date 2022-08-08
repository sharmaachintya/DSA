#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num = 234;

    int sum = 0;
    int prod = 1;

    while (num > 0)    
    {
        int temp = num % 10;
        prod = prod * temp;
        sum = sum + temp;
        num = num / 10;
    }
    cout<<(prod - sum)<<endl;
}