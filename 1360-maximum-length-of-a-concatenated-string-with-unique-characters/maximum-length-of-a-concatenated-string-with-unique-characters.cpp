class Solution {
public:
    /*
        TC => O(k * 2^n)
        SC => O(n)
    */
    bool alreadyUsed(string currStr, vector<int> &selected)
    {
        // first step check if the curr string conains duplicate strings are not 
        // if duplicates found , skip the string and return true
        vector<int> self(26,0);
        for(int i =0;i<currStr.size();i++)
        {
            if(self[currStr[i]-'a'] == 1) //  contains duplicates
                return true;
            self[currStr[i]-'a'] = 1;
        }
        // second step if curr string chaars are selected already 
        for(int i =0;i<currStr.size();i++)
        {
            if(selected[currStr[i]-'a'] == 1) //  contains duplicates
                return true;
        }
        return false;
    }
    int help(int i , vector<string> &arr,vector<int>&selected, int len)
    {
        if(i == arr.size())
        {
            return len;
        }
        if(alreadyUsed(arr[i],selected))
        {
            // skip curr string because it was already used means some chars are already used
            return help(i+1,arr,selected,len);
        }
        else
        {
            // option 1 pick ith string
            //step 1 mark chars of curr string in selected array to 1
            for(int j =0;j<arr[i].size();j++)
            {
                selected[arr[i][j]-'a']=1;
            }
            len +=arr[i].size();
            int op1  =help(i+1,arr,selected,len);
            //option 2 don't pick ith string
            for(int j =0;j<arr[i].size();j++)
            {
                selected[arr[i][j]-'a']=0;
            }
            len -=arr[i].size();
            int op2  =help(i+1,arr,selected,len);

            return max(op1,op2);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int> selected(26.0);
        return help(0,arr,selected,0);
    }
};