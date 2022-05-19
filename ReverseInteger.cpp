#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter the Number: ";
    cin>>num;
    cout<<"Before Reversing: "<<num;
    cout<<endl;
    int res, digit;
    while(num)
    {
        digit=num%10;
        if((res > INT_MAX/10) || (res < INT_MIN/10))
        {
            cout<<0;
        }
        res=res*10+digit;
        num=num/10;
    }
    cout<<"Reversed: "<<res;
}