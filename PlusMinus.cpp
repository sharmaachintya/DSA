#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    double Ncount=0, Pcount=0, Zcount=0; 
    int arr[10], n;
    cout<<"Enter the no of elements : ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for (int i=0; i<n; i++)
    {
        if (arr[i] < 0)
        {
            Ncount ++;
        }
        else if (arr[i] == 0)
        {
            Zcount++;
        }
        else if(arr[i > 0])
        {
            Pcount++;
        }
    }
    cout<<(Pcount/n)<<endl;
    cout<<(Ncount/n)<<endl;
    cout<<(Zcount/n)<<endl;
}