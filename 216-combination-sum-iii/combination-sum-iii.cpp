class Solution {
public:
    void helper(int i , int n, int k  ,vector<vector<int>> &ans, vector<int> &subset , int sum)
    {

        if(k == 0)
        {
            if(sum == n)
                ans.push_back(subset);
            return;
        }
        if(sum > n)return ;
        if( i > 9)return ;
        // take ith value
        sum += i;
        subset.push_back(i);
        helper(i+1, n , k-1 , ans, subset, sum);//  we are not inc i value because i may be included more times
        // skip ith value
        sum -=i;
        subset.pop_back();
         helper(i+1, n , k , ans, subset, sum); 

         return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(1,n,k,ans , subset , 0);
        return ans;
    }
};