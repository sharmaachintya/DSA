#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct PetrolPump{
    int petrol;
    int distance;
};

int circularTour(PetrolPump p[], int n)
{
    int start = 0;
    int balance = 0;
    int defecit = 0;

    for (int i=0;i<n;i++)
    {
        balance = p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            defecit = defecit + balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (defecit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n = 4;
    PetrolPump p[n];
    p[0].petrol = 4;
    p[1].petrol = 6;
    p[2].petrol = 7;
    p[3].petrol = 4;

    p[0].distance = 6;
    p[1].distance = 5;
    p[2].distance = 3;
    p[3].distance = 5;

    int ans = circularTour(p, n);
    cout<<ans;
}