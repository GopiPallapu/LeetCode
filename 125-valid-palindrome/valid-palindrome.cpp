class Solution {
public:
    bool isPalindrome(string s) {
        int start =0;
        int right =s.size()-1;
        while(start <= right)
        {
              if(!isalnum(s[start])){start++; continue;}
              if(!isalnum(s[right])){right--;continue;}
               if(tolower(s[start])!=tolower(s[right]))return false;
               else
              {
                  start++;
                  right--;
              }
        }
        return true;
    }
};