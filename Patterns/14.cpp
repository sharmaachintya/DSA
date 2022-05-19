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
        while(j<=i)
        {
            char ch = 'A'+count;
            cout<<ch<<" ";
            count=count+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}