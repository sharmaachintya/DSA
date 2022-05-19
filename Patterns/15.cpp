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
        while(j<=i)
        {
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}