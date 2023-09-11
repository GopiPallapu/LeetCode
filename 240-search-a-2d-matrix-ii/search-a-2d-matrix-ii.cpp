class Solution {
public:
    /*
        Approach :
        start from last row first column index and try to iterate and check
        1. if element is greater than target increment start index else decrement end index;
        TC => O(n+m) worst case
        SC => O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int  n = matrix[0].size();
        int start =0;
        int end = n-1;

        while( start<m && end>=0){
          if(matrix[start][end] == target)return true;

          else if(matrix[start][end] < target)
            start +=1;
          else 
            end -=1;
        }
        return false;
    }
};