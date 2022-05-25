#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> arr1 = {1, 4, 7, 8, 10};
    vector <int> arr2 = {2, 3, 9};
    for (int i=0;i<arr1.size();i++)
    {
        for (int j=0;j<arr2.size();j++)
        {
            if (arr1[i] > arr2[j])
            {
                swap(arr1[i],arr2[j]);
                sort(arr2.begin(),arr2.end());
                break;
            }
            else 
            {
                break;
            }
        }
    }
    for (int i=0;i<arr1.size();i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<arr2.size();i++)
    {
        cout<<arr2[i]<<" ";
    }
}