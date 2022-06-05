#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    string ransomNote = "aa";
    string magazine = "ab";
    unordered_map <char,int> mag;
    for (char c : magazine)
    {
        if (mag.find(c) != mag.end())
        {
            int count = mag[c] + 1;
            mag[c] = count;
        }
        else
        {
            mag.insert({c, 1});
        }
    }
    for (char c : ransomNote)
    {
        if (mag.find(c) == mag.end())
        {
            cout<<0;
            break;
        }
        int count = mag[c];
        if (count == 0)
        {
            cout<<0;
            break;
        }
        mag[c] = count - 1;
    }
    cout<<1;
}