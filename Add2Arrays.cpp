#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int> arr1 = {1,2,3};
    vector <int> arr2 = {4};
    int num1 = 0;
    int num2 = 0;
    for (int i=0;i<arr1.size();i++)
    {
        num1 = num1 * 10 + arr1[i];
    }
    for (int i=0;i<arr2.size();i++)
    {
        num2 = num2 * 10 + arr2[i];
    }
    int result = num1 + num2;
    cout<<result;
}