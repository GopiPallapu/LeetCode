class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n = s.length();
          int maxLen =0;
          int left =0;
          unordered_map<char ,int> charMap;
          for(int i =0;i<n;i++)
          {
                if(charMap.find(s[i])==charMap.end() || charMap[s[i]]<left){
                charMap[s[i]]=i;
                maxLen = max(maxLen , i-left+1);
                }
                else{
                    left = charMap[s[i]]+1;
                    charMap[s[i]] = i;
                }
          }
          return maxLen;
    }
};