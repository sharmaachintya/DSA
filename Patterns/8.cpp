#include<iostream>
using namespace std;
int main()
{
    int n, i=1, j, value;
    cout<<"Enter N: ";
    cin>>n;
    while (i<=n)
    {
        j=1;
        value=i;
        while(j<=i)
        {
            cout<<value<<" ";
            value=value-1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}