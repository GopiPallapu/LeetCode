class Solution {
public:
    int help(int i , vector<int>& nums , vector<int>&dp)
    {
        if( i < 0)return 0;
        if(dp[i] != -1)return dp[i];
        int op1 = help(i-2,nums , dp)+nums[i];
        int op2 = help(i-1,nums ,dp);
        return dp[i] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()  ,-1);
        return help(nums.size()-1,nums,dp);
    }
};