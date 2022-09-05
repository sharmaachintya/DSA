#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool kAnagrams(string str1, string str2, int k)
{
    if (str1.length() != str2.length())
        return false;
    
    int mp1[26] = {0};
    int mp2[26] = {0};

    for (int i=0;i<str1.length();i++)
    {
        mp1[str1[i] - 'a']++;
    }
    for (int i=0;i<str1.length();i++)
    {
        mp2[str2[i] - 'a']++;
    }

    int count = 0;
    for (int i=0;i<26;i++)
    {
        if (mp1[i] > mp2[i])
        {
            count = count + abs(mp1[i] - mp2[i]);
        }
    }
    if (count <= k)
        return true;
    else
        return false;
}

int main()
{
    string str1 = "fodr";
    string str2 = "gork";
    int k = 2;
    bool ans = kAnagrams(str1, str2, k);
    if (ans)
        cout<<"YES";
    else
        cout<<"NO";    
}