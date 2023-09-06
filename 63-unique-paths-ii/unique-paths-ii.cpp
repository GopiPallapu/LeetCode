class Solution {
public:
     int help(int i , int j , int m , int n , vector<vector<int>>& dp ,vector<vector<int>>& obstacleGrid )
    {
        // base case
        if(i == 0 && j == 0)return 1;
        if(i < 0 || j <  0 || obstacleGrid[i][j] == 1)return 0;
        if(dp[i][j] !=-1)return dp[i][j];
        // option 1 
        int op1 = help(i-1, j, m , n,dp ,obstacleGrid);
        // option 2
        int op2 = help(i , j-1,m ,n,dp,obstacleGrid);
        dp[i][j] = op1+op2;
        return op1+op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1)return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return help(m-1,n-1,m,m,dp,obstacleGrid);
    }
};