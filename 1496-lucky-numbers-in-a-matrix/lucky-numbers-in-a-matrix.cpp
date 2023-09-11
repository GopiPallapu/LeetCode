class Solution {
public:
    /*
        Approach:
        iterate through matrix and store minRow list and maxCol list and then
        iterate through whole matrix and check for each element and find it in
        the minRow list and maxCol list at index i, j
        add it to answer
        TC => O(n*m)
        SC => O(n+m)
    */
    bool checkMinInRows(int i , int j , int cols, vector<vector<int>>& matrix){
        for(int k=0;k<cols;k++){
            if(j!=k && matrix[i][k]<matrix[i][j]){
                return false;
            }
        }
        return true;
    }
    bool checkMaxInCols(int i , int j , int rows , vector<vector<int>>& matrix){
        for(int k=0;k<rows;k++){
            if(i!=k && matrix[k][j] > matrix[i][j])return false;
        }
        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> minRows ;
        vector<int> maxCols ;
        vector<int> answer ;
        int n = matrix.size();
        int m = matrix[0].size();

        // iretate through all columns and store all max column values

        for(int i =0; i < m ; i++)
        {
            int temp =INT_MIN;
            for(int j =0; j< n ; j++)
            {
                temp = max(temp , matrix[j][i]);
            }
            maxCols.push_back(temp);
        }

        // iterate through all rows and store all min row values

        for(int i =0; i< n ;i++)
        {
            int temp = INT_MAX ;
            for(int j =0 ;j< m ;j++)
            {
                temp = min(temp , matrix[i][j]);
            }
            minRows.push_back(temp);
        }

        // iterate through matrix and compare it with maxCols and minRows 
        // if it matches then add it to the ans array

        for(int i =0 ; i<n ; i++)
        {
            for(int j =0;j< m ;j++)
            {
                /*if(matrix[i][j] == minRows[i] && matrix[i][j] == maxCols[j])
                {
                    answer.push_back(matrix[i][j]);
                }*/
                if(checkMaxInCols(i,j,n,matrix) && checkMinInRows(i,j,m,matrix))
                {
                    answer.push_back(matrix[i][j]);
                }
            }
        }
        return answer;
    }
};