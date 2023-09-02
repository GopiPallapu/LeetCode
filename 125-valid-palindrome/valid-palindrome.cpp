class Solution {
public:
    bool help(int s , int e , vector<char>& str)
    {
        if(s >= e)return true;
        if(tolower(str[s])!=tolower(str[e]))return false;
        return help(s+1 ,e-1 , str);
    }
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