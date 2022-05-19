#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, i=1, j;
    cout<<"Enter N: ";
    cin>>n;
    while (i<=n)
    {
        j=1;
        int space=n-i;
        while(space)
        {
            cout<<" ";
            space=space-1;
        }
        while(j<=i)
        {
            cout<<j;
            j=j+1;
        }
        int start=i-1;
        while(start)
        {
            cout<<start;
            start=start-1;
        }
        cout<<endl;
        i=i+1;
    }
}