class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0 ; // ending point of subarray
        int n = nums.size();
        int len = INT_MAX;
        int sum = 0; // sum of current subarray
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            if(sum >= target)
            {
                while(sum>=target){
                    len = min(len,i-j+1);
                    sum -= nums[j];
                    j++;
                }
            }
        }
        return len==INT_MAX?0:len;
    }
};