#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool rotated2Places(string str1, string str2)
{
    if (str1.length() < 2 || str2.length() < 2)
    {
        if (str1 == str2)
            return true;
        else
            return false;
    }

    string temp1, temp2;
    int len = str1.length();

    temp1.append(str1.substr(2,len - 2));
    temp1.append(str1.substr(0,2));

    temp2.append(str1.substr(len - 2, 2));
    temp2.append(str1.substr(0, len - 2));

    if (temp1 == str2 || temp2 == str2)
        return true;
    
    return false;
}

int main()
{
    string str1 = "amazon";
    string str2 = "azonam";
    cout<<rotated2Places(str1, str2);    
}