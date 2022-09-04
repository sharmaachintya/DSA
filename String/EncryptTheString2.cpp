#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string encryptStr(string str)
{
    string ans = "";
    if (str.size() == 0)
        return ans;
    
    int count = 1;
    char ch = str[0];
    for (int i=1;i<str.size();i++)
    {
        if (str[i] == str[i-1])
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
                    hex += ('a' + (rem - 10));
                
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
            hex += ('a' + (rem - 10));
        
        count = count / 16;
    }
    ans += hex;
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str = "aaaaaaaaaaa";
    cout<<encryptStr(str);    
}