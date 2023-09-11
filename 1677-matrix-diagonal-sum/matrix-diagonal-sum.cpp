class Solution {
public:
    /*
        Approach :
        check n is even or odd ,  if it's even add both diagonal elements
        if it's odd , skip either primary diagonal middle or secondary diagonal middle

        TC => O(n)
        SC => O(1)
    */
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int answer =0;
        for(int i = 0 ;i< n; i++)
        {
            answer += mat[i][i];
            if( i != n-1-i)answer += mat[i][n-1-i];
        }
        return answer;
    }
};