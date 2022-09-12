#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int compareVersion(string v1, string v2)
{
    int i = 0, j = 0, n1, n2;
    while (i < v1.length() || j < v2.length())
    {
        n1 = 0;
        n2 = 0;
        while (i < v1.length() && v1[i] != '.')
        {
            n1 = n1 * 10 + (v1[i] - '0');
            i++;
        }
        while (j < v1.length() && v1[j] != '.')
        {
            n1 = n1 * 10 + (v1[j] - '0');
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
    string v1 = "2.44.90";
    string v2 = "2.44.89";    
    cout<<compareVersion(v1, v2);
}