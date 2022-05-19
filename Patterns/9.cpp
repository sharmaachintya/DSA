#include<iostream>
#include<string>
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
        while(j<=n)
        {
            char ch = 'A'+i-1;
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}