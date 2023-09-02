class Solution {
public:
    /*
        Approach :
        Recurrsive with dp TC => O(n) SC => O(n)
    */
    int help(int i, int n , vector<int>& cost, vector<int>& dp)
    {
        if(i ==n)return 0;
        if(i> n) return 100000000;
        if(dp[i] != -1)return dp[i];
        int x  =help(i+1 , n , cost,dp);
        int y = help(i+2 , n, cost,dp);
        dp[i] = cost[i] + min(x,y);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1 , -1);
        return min(help(0,n,cost , dp), help(1,n,cost,dp));
    }
};