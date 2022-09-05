#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool pangramCheck(string str)
{
    bool map[26] = {false};
    int index; 
    for (int i=0;i<str.length();i++)
    {
        if ('A' <= str[i] && 'Z' >= str[i])
            index = str[i] - 'A';
        else if ('a' <= str[i] && 'z' >= str[i])
            index = str[i] - 'a';
        
        map[index] = true;
    }
    for (int i=0;i<26;i++)
    {
        if (map[i] == false)
            return false;
    }
    return true;
}

int main()
{
    string str = "Bawds jog, flick quartz, vex nymph";
    cout<<pangramCheck(str);
}