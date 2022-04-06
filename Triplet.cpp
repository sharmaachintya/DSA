#include<iostream>
using namespace std;
int main()
{
    int arr1[3], arr2[3], arr3[2];
    int count1=0, count2=0;
    do{
        cin>>arr1[0];
        cin>>arr1[1];
        cin>>arr1[2];
        cin>>arr2[0];
        cin>>arr2[1];
        cin>>arr2[2];
    }
    while(true);
    cin>>arr1[0]>>arr1[1]>>arr1[2];
    cin>>arr2[0]>>arr2[1]>>arr2[2];
    for (int i=0; i<3; i++)
    {
        if (arr1[i]>arr2[i])
        {
            count1++;
            arr3[0]=count1;
        }
        else if (arr1[i]<arr2[i])
        {
            count2++;
            arr3[1]=count2;
        }
        else
        {
            arr3[0]=count1;
            arr3[1]=count2;
        }
    }
    for (int i=0; i<2;i++)
    {
        cout<<arr3[i]<<" ";
    }
    return 0;
}