#include<iostream>
#include<vector>
using namespace std;
bool search ( vector<vector<int>> &matrix, int target)
{
    for (int i=0;i<matrix.size();i++)
    {
        for (int j=0;j<matrix[0].size();j++)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    int target;
    cout<<"Enter the Target Value: ";
    cin>>target;
    bool ans = search(mat ,target);
    cout<<ans;
}