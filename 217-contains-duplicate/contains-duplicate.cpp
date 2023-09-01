class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> mp;
       for(auto ele : nums)
          mp[ele]++;
        for(auto var : mp)
        {
            if(var.second > 1)
                return true;
        }
        return false;
    }
};