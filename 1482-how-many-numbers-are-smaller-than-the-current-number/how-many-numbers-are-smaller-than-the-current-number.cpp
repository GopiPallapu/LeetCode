class Solution {
public:
    // [8,1,2,2,3]
    // [1,2,2,3,8]
    // 8-4 3-3 2-1 1-0
    // used ans array to sort and store count of each number in map and store back to ans array
    // TC => O(n log n) SC => O(n)
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
       /* for(int i =0 ;i< nums.size() ; i++)
        {
            int count =0;
            for(int j =0 ; j< nums.size() ; j++)
            {
                if(i!=j && nums[j] < nums[i])
                    count +=1;
            }
            ans.push_back(count);
        }*/
        vector<int> ans = nums;
        sort(ans.begin() , ans.end());
        unordered_map<int,int> mp;
        for(int i = nums.size()-1;i>=0;i--)
        {
            mp[ans[i]] =i;
        }
        for(int i =0; i< nums.size();i++)
            ans[i] = mp[nums[i]];
        return ans;
    }
};