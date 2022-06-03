#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s = "pwwkew";
    vector <int> dict(256,-1);
    int start = -1, maxLen = 0;
    for (int i=0;i<s.size();i++)
    {
        if (dict[s[i]] > start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    cout<<maxLen;
}