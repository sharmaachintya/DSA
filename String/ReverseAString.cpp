#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(char name[], int len)
{
    int s = 0;
    int e = len - 1;

    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i=0;name[i] != '\0';i++)
    {
        count++;
    }
    return count;
}
int main()
{
    char name[10];
    cout<<"Enter the name: ";
    cin>>name;

    int len = getLength(name);  

    reverse(name, len); 
    cout<<name; 
}