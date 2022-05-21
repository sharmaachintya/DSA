class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector <int> ans;
        int count=1;
        sort(arr.begin(),arr.end());
        for (int i=0;i<arr.size();i++)
        {
            if (arr.size() == 2)
            {
                return false;
            }
            else if (arr[i+1] == arr[i])
            {
                count++;
                ans.push_back(count);
            }
            // else
            // {
            //     ans.push_back(count);
            // }
        }
        for (int i=0;i<ans.size();i++)
        {
            if(ans[i+1] == ans[i])
            {
                return false;
            }
        }
        return true;
    }
};