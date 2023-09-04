class Solution {
public:
    void helper( int i , int n , vector<int> &nums , int x , int &sum)
    {
        if(i == n)
        {
            sum +=x;
            return;
        }
        // option 1 include ith index
        helper(i+1 ,n , nums , x^nums[i] ,sum);
        // option 2 don't include
         helper(i+1 ,n  ,nums , x ,sum);
    }
    int subsetXORSum(vector<int>& nums) {
        int n =nums.size();
        int sum =0;
        int x =0;
        helper(0,n,nums,x,sum);
        return sum;
    }
};