class Solution {
public:
    /*
        Approach:
        1. m*n Brute
        2. m * log n || n * log m
        3. log (m*n)
        4. m+n -- Best
        SC => O(1)
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m-1;
        while(left >=0 && left < n && right >=0 && right < m)
        {
            if(matrix[left][right] == target)return true;
            else if(matrix[left][right] > target)
            {
                right --;
            }
            else
                left ++;
        }
        return false;

    }
};