#include<iostream>
using namespace std;
int main()
{
    int n, i=1, j;
    cout<<"Enter N: ";
    cin>>n;
    while (i<=n)
    {
        j=1;
        while(j<=i)
        {
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}