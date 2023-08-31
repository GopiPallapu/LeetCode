class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> elements;
        for(int i=0;i<n;i++){
          if(elements.find(target-nums[i])!=elements.end()){
            auto it = elements.find(target-nums[i]);
            return { it->second,i};
          }
          elements[nums[i]]=i;
        }
        return {};
    }
};