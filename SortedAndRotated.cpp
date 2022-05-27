#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr = {3,4,5,1,2}; 
    int count = 0;
    for (int i=1;i<arr.size();i++)
    {
        if (arr[i-1] > arr[i])
        {
            count++;
        }
    }
    if (arr[arr.size() - 1] > arr[0])
    {
        count++;
    }
    if (count <=1 )
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}