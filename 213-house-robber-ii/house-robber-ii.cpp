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
        vector<int>dp(nums.size(),-1);
        vector<int> t1 , t2;
        if(nums.size() == 1)return nums[0];
        for(int i =0; i< nums.size() ; i++)
        {
            if(i!=0)t1.push_back(nums[i]);
            if(i!=nums.size()-1)t2.push_back(nums[i]);
        }
        int op1 = help(t1.size() -1,t1, dp);
        for(int i =0;i<dp.size();i++)
            dp[i] = -1;
        int op2 = help(t2.size() -1, t2,dp);
        return max(op1,op2);

    }
};