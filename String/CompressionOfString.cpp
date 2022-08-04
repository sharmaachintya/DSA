#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int i = 0;
    int n = chars.size();
    int ansIndex = 0;

    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        chars[ansIndex++] = chars[j];
        int count = j - i;

        if (count > 1)
        {
            string cnt = to_string(count);
            for (auto ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    cout<<ansIndex;
}
