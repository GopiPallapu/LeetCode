class Solution {
public:
    /*
        Approach :
        recurrsive approach without dp TC => O(2^n) SC => O(n)
        recurrsive approach with dp TC => O(n) SC => O(n)
    */
    int help(int n , vector<int>& dp)
    {
        if(n == 0 || n == 1)return n;
        if(dp[n] != -1)return dp[n];
        int partial_ans1 = help(n-1 , dp);
        int partial_ans2 = help(n-2 , dp);
        dp[n] = partial_ans1 + partial_ans2;
        return dp[n];
    }
    int fib(int n) {
       vector<int> dp(n+1 , -1);
        return help(n , dp);
    }
};