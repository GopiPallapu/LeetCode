class Solution {
public:
    /*
        Approach :
        we have to iterate for each 3*3 matrix size and get max number and store it in answer matrix.
        TC => O(3 * (m*n))
        Optimized  =  TC => O(n-2 * m-2) => O( (n-2)^2)
        SC => O(1)
    */
    int getMax(vector<vector<int>>& grid ,int i, int j)
    {
        int num = INT_MIN;
        for(int r  =i;r < i+3 ; r++)
        {
            for(int c = j ;c < j+3; c++)
            {
                num = max(num, grid[r][c]);
            }
        }
        return num;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<int>> ans (n-2 , vector<int>(m-2)) ;
        for(int i =1 ; i<= n-2;i++)
        {
           // vector<int> temp;
            for(int j =1;j<= m-2;j++)
            {
                int maxNum =0;
                maxNum = max({maxNum , grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxNum = max({maxNum , grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxNum = max({maxNum , grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});
                ans[i-1][j-1] = maxNum;
            }
        }
        return ans;
    }
};