class Solution {
public:
    /*
        Approach :
        we have to iterate for each 3*3 matrix size and get max number and store it in answer matrix.
        TC => O(3 * (m*n))
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
        vector<vector<int>> ans ;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0 ; i< n-2;i++)
        {
            vector<int> temp;
            for(int j =0;j< m-2;j++)
            {
                temp.push_back(getMax(grid,i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};