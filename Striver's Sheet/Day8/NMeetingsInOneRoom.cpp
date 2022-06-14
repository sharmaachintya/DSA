#include<iostream>
#include<algorithm>
using namespace std;
struct meeting{
    int start;
    int end;
    int pos;
};
bool comparator(struct meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    else
        return false;
}

vector<int> maxMeetings(int s[], int f[], int n)
{
    struct meeting m[n];
    for (int i=0;i<n;i++)
    {
        m[i].start = s[i];
        m[i].end = f[i];
        m[i].pos = i+1;
    }
    sort(m, m+n, comparator);

    vector <int> ans;
    int limit = m[0].end;
    ans.push_back(m[0].pos);

    for (int i=1;i<n;i++)
    {
        if (m[i].start > limit)
        {
            limit = m[i].end;
            ans.push_back(m[i].pos);
        }     
    }
    return ans;
}

int main()
{
    int n = 6;
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9}; 

    vector <int> ans = maxMeetings(s, f ,n);
    for (int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }


}