#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector <int>> arr={{1,2,3},{4,5,6},{7,8,9}};
    cout<<"BEFORE ROTATION: "<<endl;
    for (int i=0;i<arr.size();i++)
    {
        for (int j=0;j<arr.size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0;i<arr.size();i++)                                   // Transposing the MATRIX
    {
        for (int j=i;j<arr[i].size();j++)
        {
            if (i!=j)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    for (int i=0;i<arr.size();i++)                                   // Swapping the elements 
    {
        for (int j=0;j<arr.size()/2;j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][arr.size()-j-1];
            arr[i][arr.size()-j-1] = temp;
        }
    }
    cout<<"AFTER ROTATION: "<<endl;
    for (int i=0;i<arr.size();i++)
    {
        for (int j=0;j<arr.size();j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}