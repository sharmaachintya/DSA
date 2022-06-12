#include<iostream>
using namespace std;
int kadane(int arr[],int size)
{
    int CurSum=0, MaxSum=0;
    for (int i=0;i<size;i++)
    {
        CurSum = CurSum + arr[i];
        if (CurSum > MaxSum)
        {
            MaxSum = CurSum;
        }
        if (CurSum < 0)
        {
            CurSum = 0;
        }
    }
    return MaxSum;
}
int main()
{
    int arr[5]={5,-4,-2,6,-1}; 
    int n=5, res;
    res=kadane(arr, n);
    cout<<res;
}