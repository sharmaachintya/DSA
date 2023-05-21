#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(string ver1, string ver2)
{
    int i = 0, j = 0, n1, n2;
    while (i < ver1.length() || j < ver2.length()) 
    {
        n1 = 0;
        n2 = 0;
        while (i < ver1.length() && ver1[i] != '.')
        {
            n1 = n1 * 10 + (ver1[i] - '0');
            i++;
        }
        while (j < ver2.length() && ver2[j] != '.')
        {
            n2 = n2 * 10 + (ver2[j] - '0');
            j++;
        }
        if (n1 > n2)
            return 1;
        else if (n2 > n1)
            return -1;
        i++;
        j++;
    }
    return 0;
}

int main()
{
    string ver1 = "1.0";
    string ver2 = "1.0.0";
    cout<<solve(ver1, ver2);
}