#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int validIP(string str)
{
    int counter = 0;
    for (int i=0;i<str.length();i++)
    {
        if (str[i] == '.')
            counter++;
    }
    if (counter != 3)
        return 0;
    
    unordered_set<string> st;
    for (int i=0;i<256;i++)
    {
        st.insert(to_string(i));
    }
    counter = 0;
    string temp = "";
    for (int i=0;i<str.length();i++)
    {
        if (str[i] != '.')
            temp = temp + str[i];
        else
        {
            if (st.count(temp) != 0)
                counter++;
            temp = "";
        }
    }
    if (st.count(temp) != 0)
        counter++;
    if (counter == 4)
        return 1;
    else
        return 0;
}

int main()
{
    string str = "222.111.111.111";
    cout<<validIP(str);    
}