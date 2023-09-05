class Solution {
public:
    void helper(int i , int n , int k , vector<vector<int>> &ans ,vector<int> &subset )
    {
        if(k == subset.size())
        {
            ans.push_back(subset);
            return;
        }
       // if( k > n-i+1)return;
        if(i > n) return ;
        subset.push_back(i);
        helper(i+1,n,k,ans,subset);
        subset.pop_back();
        helper(i+1,n,k,ans,subset);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(1,n,k,ans,subset);
        return ans;
    }
};