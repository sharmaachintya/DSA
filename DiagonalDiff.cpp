#include<iostream>
using namespace std;
int main()
{
    int D1sum=0, D2sum=0, n;
    int arr[10][10];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i == j)
            {
                D1sum=D1sum+arr[i][j];
            }
            if( (i+j) == (n-1) )
            {
                D2sum=D2sum+arr[i][j];
            }
        }
    }
    cout<<(D1sum-D2sum);
}