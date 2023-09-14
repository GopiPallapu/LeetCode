class Solution {
public:
    /*
        Approach :
        1.using map we can store count of each value
        and by using index pointer iterate and store exactly for two numbers
        TC => O(n)
        SC => O(n)
        2. using two pointers will ietrate through array and using count function will sove it
        TC => O(n)
        SC => O(1)
    */
    int removeDuplicates(vector<int>& nums) 
    {
        int index =0;
        unordered_map <int,int> mp;
        int n = nums.size();
        int i =0;
        /*while( i < n)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] <= 2)
            {
                nums[index] =nums[i];
                index++;
            }
            i++;
        }*/
        while( i< n)
        {
            int count =0;
            int j = i;
            while( j < n && nums[j] == nums[i])
            {
                if(count<2)
                {
                    nums[index] = nums[i];
                    index++;
                }
                count ++;
                j++;
            }
            i =j;
        }
        return index;
    }
};