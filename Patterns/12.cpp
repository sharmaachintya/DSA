#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n, i=0, j;
    cout<<"Enter N: ";
    cin>>n;
    while (i<=n)
    {
        j=1;
        while(j<=n)
        {
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}