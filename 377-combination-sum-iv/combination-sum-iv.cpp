class Solution {
public:
    void helper(int i , int target , int sum , vector<int> &nums , int n , vector<int>& subset , vector<vector<int>> &ans)
    {
        if(sum == target)
        {
            ans.push_back(subset);
            return;
        }
        if(sum  > target)return ;
        if(i >= n)return ;
        sum +=nums[i];
        subset.push_back(nums[i]);
       helper(i , target ,sum , nums,n , subset , ans);
        sum -=nums[i];
        subset.pop_back();
        helper(i+1  ,target , sum , nums , n ,subset,ans);

        return ;
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
        vector<vector<int>> ans;
        vector<int> subset;
         //helper(0,target,0,nums,n,subset,ans);
         for(auto var : ans)
         {
             for(auto i : var)
                cout<<i<<" ";
            cout<<endl;
         }
         vector<int>dp(target+1, -1);
         return count(nums,target,n , dp);
         //return ans.size();
    }
};