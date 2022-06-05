#include<iostream>
using namespace std;
int main()
{
    string s = "rat";
    string t = "car";
    int freqT[26] = {0};
    int freqS[26] = {0};
    for (char c : s)
    {
        freqS[c - 'a']++;
    }
    for (char c : t)
    {
        freqT[c - 'a']++;
    }
    for (int i=0;i<26;i++)
    {
        if (freqS[i] != freqT[i])
        {
            cout<<0<<endl;
            break;
        }
    }
    cout<<1<<endl;
}