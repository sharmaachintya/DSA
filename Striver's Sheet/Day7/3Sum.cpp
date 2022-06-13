#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> ans;
    vector <int> num = {1,2,0,2,2,0,1,0,-1,-1,-2,-2,-1};
    sort(num.begin(), num.end());

    for (int i=0;i<num.size()-2;i++)
    {
        if (i == 0 || (i > 0 && num[i] != num[i-1]))
        {
            int lo = 1;
            int hi = num.size()-1;
            int sum = 0 - num[i];
            while (lo < hi)
            {
                if (num[lo] + num[hi] == sum)
                {
                    vector<int> temp;
                    temp.push_back(num[i]);
                    temp.push_back(num[lo]);
                    temp.push_back(num[hi]);
                    ans.push_back(temp);
                    while (lo < hi && num[lo] == num[lo+1])
                        lo++;
                    while (lo < hi && num[hi] == num[hi-1])
                        hi--;
                lo++;
                hi--;
                }
                else if (num[lo] + num[hi] > sum)
                {
                    lo++;
                }
                else
                {
                    hi--;
                }
            }
        }
    }
    for (int i=0;i<ans.size();i++)
    {
        for (int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}