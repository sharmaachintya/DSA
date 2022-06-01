#include<iostream>
#include<vector>
using namespace std;
void solve (string digits, string output, int index, vector <int> &ans, string mapp[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int num = digits[index] - '0';
    string val = mapp[num];
    for (int i=0;i<val.length();i++)
    {
        output.push_back(val[i]);
        solve(digits, output, i+1, ans, mapp);
        output.pop_back();
    }
}
int main()
{
    string digits = "23";
    vector <string> ans;
    if (digits.length() == 0)
    {
        cout<<"[ ]";
    }
    int index = 0;
    string output = "";
    string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits, output, index, ans, mapp);
}