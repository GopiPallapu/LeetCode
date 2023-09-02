class Solution {
public:
     void ValidParenthesis(vector<string>&ans,int n, int start,int end , string str){
        //base case
        if(str.length()==n*2)
        {
            ans.push_back(str);
            return;
        }
        if(start<n)
            ValidParenthesis(ans,n,start+1,end,str+"(");
        if(end<start)
            ValidParenthesis(ans,n,start,end+1,str+")");
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ValidParenthesis(ans,n,0,0,"");
        return ans;
    }
};