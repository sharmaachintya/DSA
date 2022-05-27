#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr1 = {1,2,3,4};
    int start = 0;
    int end = arr1.size()-1;
    while (start <= end)
    {
        swap(arr1[start], arr1[end]);
        start++;
        end--;
    }
    for (int i=0;i<arr1.size();i++)
    {
        cout<<arr1[i]<<" ";
    }
}