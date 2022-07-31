#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getLength(char arr[])
{
    int count = 0;
    for (int i=0;arr[i] != '\0';i++)
    {  
        count ++;
    }
    return count;
}
int main()
{
    char name[10];

    cout<<"Enter the name: ";
    cin>>name;

    cout<<"Length of the name is: "<<getLength(name);
}