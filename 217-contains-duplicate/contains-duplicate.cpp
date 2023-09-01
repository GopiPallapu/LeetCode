class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(auto ele : nums)
        {
            if(mp[ele] >= 1)
                return true;
            mp[ele]++;
        }
        return false;
    }
};