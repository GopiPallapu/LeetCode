class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int answer =0;
        if( n % 2 == 0 )
        {
            for(int i = 0 ;i< n; i++)
            {
                answer += mat[i][i];
                answer += mat[i][n-1-i];
            }
        }
        else
        {
            for(int i = 0 ;i< n; i++)
            {
                answer += mat[i][i];
                if( i != n-1-i)answer += mat[i][n-1-i];
            }
        }
        return answer;
    }
};