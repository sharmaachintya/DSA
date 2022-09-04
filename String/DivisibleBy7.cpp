#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool divisibleBy7(string num)
{
    int sum = 0;
    for (int i=0;i<num.size();i++)    
    {
        int digit = num[i] - '0';
        sum = sum*10 + digit;
        sum = sum % 7;
    }
    if (sum == 0)
        return 1;
    else
        return 0;
}

int main()
{
    string num = "8955795758";
    cout<<divisibleBy7(num);
}