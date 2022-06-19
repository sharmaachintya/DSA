#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if(s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}

void solve(int ind, string s, vector<string> &ds, vector<vector<string>> &ans)
{
    // Base Case
    if (ind == s.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i=ind;i<s.size();i++)
    {
        if (isPalindrome(s, ind, i))
        {
            ds.push_back(s.substr(ind, i-ind+1));
            solve(i+1, s, ds, ans);
            ds.pop_back();
        }
    }
}


int main()
{
    string s = "aab";
    vector<string> ds;
    vector<vector<string>> ans;
    solve(0, s, ds, ans);
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}