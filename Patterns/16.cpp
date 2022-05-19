#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, i=1, j, count=0;
    cout<<"Enter N: ";
    cin>>n;
    while (i<=n)
    {
        j=1;
        char ch = 'A'+n-i;
        while(j<=i)
        {
            cout<<ch<<" ";
            ch=ch+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}