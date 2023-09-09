class Solution {
public:
    /*
        Approach :
        Using recurrsive solution 
        TC => O(2^n)
        SC => O(n)
    */
    bool helper(int left, int right, int sc1 ,int sc2, vector<int>& nums ,bool flag)
    {
            // base case
            if(left > right)
                return sc1 >= sc2;
            // case 1
            if(flag == 1)
            {
                bool op1 = helper(left+1,right,sc1+nums[left],sc2,nums,!flag);
                bool op2 = helper(left,right-1,sc1+nums[right],sc2,nums,!flag);
                return op1 || op2;
            }
            else
            {
                bool op3 = helper(left+1,right,sc1,sc2+nums[left],nums,!flag);
                bool op4 = helper(left,right-1,sc1,sc2+nums[right],nums,!flag);
                return op3 && op4;
            }
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return helper(0,n-1,0,0,nums , true);
    }
};