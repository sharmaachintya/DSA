#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> arr = {9};
    int carry = 1;
    reverse(arr.begin(), arr.end());
    for (int i=0;i<arr.size();i++)
    {
        int num = arr[i] + carry;
        carry = num / 10;
        arr[i] = num % 10;
    }
    if (carry != 0)
    {
        arr.push_back(carry);
    }
    reverse(arr.begin(), arr.end());
    for (int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}