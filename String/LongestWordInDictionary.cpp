#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubseq(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();

    int j = 0;
    for (int i=0; i<n && j<m;i++)
    {
        if (str1[j] == str2[i])
            j++;
    }
    return (j==m);
}

string longestWord(vector<string> dict, string str)
{
    int len = 0;
    string res = "";

    for (string word : dict)
    {
        if (len < word.length() && isSubseq(word, str))
        {
            len = word.length();
            res = word;
        }
    }
    return res;
}

int main()
{
    vector<string> dict = {"ale", "apple", "monkey", "plea"};
    string str = "abpcplea";
    cout<<longestWord(dict, str);
}