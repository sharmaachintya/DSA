#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string solve(string str)
{
    int count = 1;
    string ans = "";
    char ch = str[0];
    for (int i=1;i<str.size();i++)
    {
        if (str[i-1] == str[i])
            count++;
        else
        {
            ans += ch;
            string hex = "";
            while (count != 0)
            {
                int rem = count % 16;
                if (rem < 10)
                    hex += ('0' + rem);
                else
                    hex += ('a' + rem - 10);
                count = count / 16;
            }
            ans += hex;
            count = 1;
            ch = str[i];
        }
    }
    ans += ch;
    string hex = "";
    while (count != 0)
    {
        int rem = count % 16;
        if (rem < 10)
            hex += ('0' + rem);
        else
            hex += ('a' + rem - 10);
        count = count / 16;
    }
    ans += hex;
    reverse(ans.begin(), ans.end());
    return ans;
} 
 
int main()
{
    string str = "aaaaaaaaaaa";
    cout<<solve(str);
}