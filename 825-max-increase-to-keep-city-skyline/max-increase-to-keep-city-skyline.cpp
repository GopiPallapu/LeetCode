class Solution {
public:
    /*
        Approach :
        Iterate through matrix and find max from row wize and column wize and take min of both.
        then add it to new matrix and take diff of two matrices.
        TC => O(n^2)
        SC => O(n^2)
    */
    int getMax(int i , int j , int n ,int m ,vector<vector<int>>& grid)
    {
        int rowMax = 0 , colMax = 0;
        for(int r = 0 ; r < m ;r++)
        {
            rowMax = max(rowMax , grid[i][r]);
            colMax = max(colMax , grid[r][j]);
        }
        return min(rowMax, colMax);
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // sum = 57
        // newSum = 92
        // difference = 92-57 =  35
        int n = grid.size();
        int m = grid[0].size();
        int originalSum =0;
        int newSum =0;
        vector<vector<int>> answerMatrix(n ,vector<int>(m,0));
        for(int i =0 ;i< n;i++)
        {
            for(int j =0 ;j < m ; j++)
            {
                answerMatrix[i][j] =  getMax(i ,j ,n,m, grid);
                originalSum +=grid[i][j];
                newSum +=answerMatrix[i][j];
               // cout<< answerMatrix[i][j] <<",";
            }
           // cout <<endl;
        }

        return abs(newSum - originalSum);
    }
};