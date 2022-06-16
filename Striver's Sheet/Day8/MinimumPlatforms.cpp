#include<iostream>
#include<algorithm>
using namespace std;

int minimumPlat(vector<int> start, vector<int> end)
{
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int n = start.size();
    int plat = 1, max = 1;
    int i = 1, j = 0; 
    while (i < n && j < n)
    {
        if (start[i] <= end[j])
        {
            plat++;
            i++;
        }
        else if (start[i] > end[j])
        {
            plat--;
            j++;
        }
        if (plat > max)
        {
            max = plat;
        }
    }
    return max;
}

int main()
{
    vector<int> start = {120, 200, 700, 850, 50, 550};
    vector<int> end = {550, 700, 1000, 500, 600, 900}; 

    int ans = minimumPlat(start, end);  
    cout<<ans;
}
