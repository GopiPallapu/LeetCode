class Solution {
public:
    int  helper(int i , int target , int sum , vector<int> &nums , int n )
    {
        if(sum == target)
        {
           return 1;
        }
        int temp =0;
        if(sum  > target)return 0;
        if(i >= n)return 0;
        sum +=nums[i];
       temp +=helper(i , target ,sum , nums,n );
        sum -=nums[i];
       temp += helper(i+1  ,target , sum , nums , n);

        return temp ;
    }
    int count(vector<int> &nums , int target , int n ,vector<int>& dp )
    {
        if(target == 0)return 1;
        if(dp[target] > -1)return dp[target];
        int temp =0;
        for(int i =0;i<n;i++)
        {
            if(target >= nums[i])
                temp +=count(nums , target-nums[i],n,dp);
        }
        dp[target] = temp;
        return temp;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int temp =0;
         //helper(0,target,0,nums,n);
         vector<int>dp(target+1, -1);
         return count(nums,target,n , dp);
         //return temp;
    }
};