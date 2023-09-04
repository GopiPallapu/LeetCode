class Solution {
public:
    /*
        Approach : 
        using recurrsion we solve small problem of find first unique permutation and ask recurrsion to solve
        rest
        then backtrack and do for other combination
        TC => O(n*n)
        SC => O(n)
    */
    void helper(int i , int n , vector<vector<int>> &ans , vector<int> &nums)
    {
        if( i>= n)
        {
            ans.push_back(nums);
            return ;
        }
        for(int index = i ; index < n;index++)
        {
            swap(nums[i] , nums[index]);
            helper(i+1 , n , ans ,nums);
            swap(nums[i] , nums[index]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        helper(0,n,ans,nums);
        return ans;
    }
};