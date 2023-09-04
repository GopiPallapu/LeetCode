class Solution {
public:
     bool isValid(int i , int j , int n ,  vector<vector<char>> &matrix)
    {
        int tempi =i;
        int tempj =j;
        // row check
        for(int k =0;k<n;k++)
        {
            if(matrix[tempi][k] == 'Q') // row check
                return false;
            if(matrix[k][tempj] == 'Q') // col check
                return false;
        }
        tempi = i;
        tempj = j;
        // top left diagonal
        while(tempi >=0 && tempj >=0)
        {
            if(matrix[tempi][tempj] == 'Q')
                return false;
            tempi--;
            tempj--;
        }
        tempi = i;
        tempj = j;
        // top right diagonial
        while(tempi >= 0 && tempj <= n - 1)
        {
            if(matrix[tempi][tempj] == 'Q')
                return false;
            tempi--;
            tempj++;
            
        }
        return true;
    }
     int helper(int i , int n ,  vector<vector<char>> &matrix)
    {
        if(i == n)
        {
           return 1;
        }
        int ans =0;
        for(int j = 0;j<n;j++)
        {
            if(isValid(i,j ,n , matrix))
            {
                matrix[i][j] ='Q';
                ans +=helper(i+1 , n,matrix);
                matrix[i][j] ='.';
            }
        }
        return ans ;
    }
    int totalNQueens(int n) {
        vector<vector<char>> matrix (n , vector<char>(n,'.'));
         return helper(0,n , matrix);
    }
};