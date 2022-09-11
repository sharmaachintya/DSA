#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int impAtoi(string str)
{
    int sign = 0;
    int ans = 0;
    for (int i=0;i<str.length();i++)
    {
        if (str[i] == 45)
        {
            sign = 1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i] == '0')
                ans = str[i] - 48;
            else
                ans = (ans * 10) + str[i] - 48;
        }
        else
            return -1;
    }
    if (sign == 1)
        ans = 0 - ans;
    return ans;
}

int main()
{
    string str = "1246";
    cout<<impAtoi(str);    
}