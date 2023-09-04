class Solution {
public:
    void helper(int i , int n , string &s , vector<string> &ans , string &temp ,  unordered_map<char ,string> &mp)
    {
        if(i == n)
        {
            ans.push_back(temp);
            return ;
        }
        string str = mp[s[i]];
        for(int index = 0 ; index < str.size() ; index++)
        {
            temp.push_back(str[index]);
            helper(i+1 , n , s , ans , temp , mp);
            temp.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char ,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        string temp;
        if(digits == "")return {};
        helper(0,digits.size() ,digits, ans , temp , mp);
        return ans;
    }
};