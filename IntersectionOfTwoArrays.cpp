#include<iostream>
#include<vector>
using namespace std;
vector <int> InterSec(int arr1[], int arr2[], int n1, int n2)
{
    vector <int> arr;
    for(int i=0;i<n1;i++)
    {
        int element = arr1[i];
        for(int j=0;j<n2;j++)
        {
            if(element == arr2[j])
            {
                arr.push_back(element);
                arr2[j] = -99;
                break;
            }
        }
    }
    return arr;
}
int main()
{
    int arr1[10], arr2[10];
    int n1, n2;
    cout<<"Enter the size of first Array: ";
    cin>>n1;
    cout<<"Enter the size of Second Array: ";
    cin>>n2;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    int res = InterSec(arr1, arr2, n1, n2);
    cout<<res;
}