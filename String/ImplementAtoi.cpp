#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Iatoi(string str)
{
    int out;
    int sign = 0;
    for (int i=0;i<str.length();i++)
    {
        if (i == 0 && str[i] == 45)
        {
            sign = 1;
            continue;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (i == 0)
                out = str[i] - 48;
            else
                out = out*10 + (str[i] - 48);
        }
        else
            return -1;
    }   
    if (sign == 1)
        out = 0 - out;
    return out;
}

int main()
{
    string str = "123";
    cout<<Iatoi(str);    
}