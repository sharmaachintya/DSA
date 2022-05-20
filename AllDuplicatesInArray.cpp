class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> ans;
        sort(nums.begin(),nums.end());
        int check = -1;
        for (int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
            {
                if(check != nums[i])
                {
                    ans.push_back(nums[i]);
                    check = -1;
                }
                else
                    continue;
            }
        }
        return ans;
        
    }
};