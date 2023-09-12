class Solution {
public:
    /*
        Approach :
        iterate and store frequency of each char in map
        then iterate through map and check for each frequency and make it unique to store it in set 
        TC => O(n)
        SC => O(n)
    */
    int minDeletions(string s) {
        unordered_map<int,int> mpCnt ;
        unordered_set<int> chars ;
        for(int i =0 ; i < s.size() ; i++)
        {
            mpCnt[s[i]]++;
        }
        int answer =0;
        for(auto var : mpCnt)
        {
            int freq = var.second;
            while(freq > 0 && chars.find(freq)!=chars.end())
            {
                freq -=1;
                answer +=1;
            }
            chars.insert(freq);
        }
        return answer;
    }
};