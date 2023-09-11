class Solution {
public:
    /*
        Approach :
        TC => O(n+m)
        SC => O(n+m)
    */
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m =1 ;
        // find the rows and columns size
        for(int i = 0 ;i < n ; i++)
        {
            int siz = nums[i].size();
            m = max(m , siz);
        }
        vector<vector<int>> diagonalElements ( n+m ) ;
       // store all the diagonal elemnets in a 2D array form matrix
        vector<int> answer ;
        for(int i =0 ; i < n ; i++)
        {
            for(int j = 0 ; j < nums[i].size() ; j++)
            {
                diagonalElements[i+j].push_back(nums[i][j]);
            }
        }
        // iterate through all diagonal array , reverse those and add it to answer
        for(int i =0 ;i < (n+m) ; i++)
        {
            reverse(diagonalElements[i].begin() , diagonalElements[i].end());
            for(int k =0 ; k < diagonalElements[i].size() ; k++)
            {
                answer.push_back(diagonalElements[i][k]);
            }
        }
        return answer;
    }
};