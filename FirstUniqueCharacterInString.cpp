#include<iostream>
using namespace std;
int main()
{
    string s = "leetcode";
    int freq[26] = {0};
    for (int i=0;i<s.size();i++)
    {
        freq[s.at(i) - 'a']++;
    }
    for (int i=0;i<s.size();i++)
    {
        if (freq[s.at(i) - 'a'] == 1)
        {
            cout<<i<<endl;
            break;
        }
        else
        {
            cout<<-1;
            break;
        }
    }
}