class Solution {
public:
    void helper(int i , int n , vector<int>& nums , vector<vector<int>>& res , vector<int>& temp)
    {
        if( i == n)
        {
            res.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        helper(i+1 , n , nums , res , temp);
        temp.pop_back();
          helper(i+1 , n , nums , res , temp);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tt;
        int n = nums.size();
        helper(0,n,nums,result,tt);
        return result;
    }
};