#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
vector<string> powerSet(string s)
{
    vector<string>ans;
    int n = pow (2, s.length());
    for (int num=0;num<n;num++)
    {
        string sub = "";
        for (int i=0;i<s.length();i++)
        {
            if (num & (1 << i))
            {
                sub = sub + s[i];
            }
        }
        ans.push_back(sub);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s = "abc";
    vector<string> ans = powerSet(s);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}