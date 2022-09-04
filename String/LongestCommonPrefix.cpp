#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string lCommonP(vector<string> arr, int n)
{
    string ans = "";
    for (int i=0;i<n;i++)
    {
        char ch = arr[0][i];
        bool match = true;
        for (int j=1;j<arr.size();j++)
        {
            if (ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match == false)
            break;
        else
            ans.push_back(ch);
    }
    if (ans.size() == 0)
        return "-1";
    else
        return ans;
}   

int main()
{
    vector<string> arr = {"flower","flow","flight"};
    int n = arr.size();
    cout<<lCommonP(arr, n);    
}