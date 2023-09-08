class Solution {
public:
    /*
        Approach :
        using two pointers left and right check squares and compare and fill the ans array from right side with bigger square
        TC => O(n)
        SC => O(1)
    */
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n,0);;
        int k = n-1;
        int left =0;
        int right = n-1;
        while( left <= right)
        {
            if(nums[left]*nums[left] > nums[right]*nums[right])
            {
                ans[k] = nums[left]*nums[left];
                k--;
                left++;
            }
            else
            {
                ans[k] = nums[right]*nums[right];
                k--;
                right--;
            }
        }
        return ans;
    }
};