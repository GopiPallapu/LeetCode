class Solution {
public:
    /*
        Approach :
        get all diagonal elements and check prime for each element
        TC => O(n * sqrt(n))
        SC => O(1)
    */
    int largestPrimeNumber(vector<int>& nums)
    {
        int answer =0;
        for( int i =0 ; i < nums.size() ; i++ )
        {
            int flag =0;
            if(nums[i] == 1) continue; 
            for(int j =2 ; j*j <= nums[i] ; j++ )
            {
                if(nums[i] % j == 0)
                {
                    flag = 1 ;
                    break;
                }
            }
            if(flag == 0)
            {
                answer = max(answer , nums [i]);
            }
        }
        return answer;
    }
    int diagonalPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> diagonalNumbers ;
        for(int i = 0 ;i< n; i++)
        {
            diagonalNumbers.push_back(mat[i][i]);
            if( i != n-1-i)
                diagonalNumbers.push_back(mat[i][n-1-i]);
        }
        return largestPrimeNumber(diagonalNumbers);
    }
};