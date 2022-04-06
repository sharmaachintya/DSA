#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cout<< setw(n)<< right<< string(i, '#')<<endl;
    }
}