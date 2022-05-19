#include<iostream>
using namespace std;
int main()
{
    int rows, cols;
    int arr[10][10];
    cout<<"Enter the number of Rows: ";
    cin>>rows;
    cout<<"Enter the number of Columns: ";
    cin>>cols;
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            cout<<"Enter Element["<<i<<"]"<<"["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }
    int column=1;
    for (int i=0;i<rows;i++)
    {
        if (arr[i][0] == 0)
        {
            column=0;           // Updating the Column variable to false
        }
        for (int j=1;j<cols;j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;  // Updating the row dummy matrix to 0
                arr[0][j] = 0;  // Updating the column dummy matrix to 0
            }
        }
    }
    for (int i=rows-1;i>=0;i--)
    {
        for (int j=cols-1;j>=1;j--)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
            {
                arr[i][j] = 0;
            }
        }
        if (column == 0)
        {
            arr[i][0] = 0;
        }
    }
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}