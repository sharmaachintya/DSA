#include<iostream>
#include<vector>
using namespace std;
int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int count = 0;
    while (n > 0)
    {
        if(n % 2 == 1)
        {
            count++;
        }
        n = n / 2;
    }
    cout<<count;
}
