#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPower(int n)
{
    return (n && !(n & n-1));
}

int main()
{
    cout<<isPower(15)<<endl;
}