class Solution {
public:
    void helper(int i , int n , vector<vector<int>> &ans , vector<int> &nums)
    {
        if( i>= n)
        {
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> s;
        for(int index = i ; index < n;index++)
        {
            if(s.find(nums[index])!=s.end())continue;
            s.insert(nums[index]);
            swap(nums[i] , nums[index]);
            helper(i+1 , n , ans ,nums);
            swap(nums[i] , nums[index]);
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        helper(0,n,ans,nums);
        return ans;
    }
};