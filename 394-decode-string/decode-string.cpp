class Solution {
public:
    string decode (int &i , string &s)
    {
        string result ="";
        while(i< s.size() && s[i] !=']')
        {
            if(isdigit(s[i]))
            {
                int k =0;
                while(i<s.size() && isdigit(s[i]))
                {
                    k = k*10 + s[i]-'0';
                    i++;
                }
                i++;
                string r = decode(i,s);
                while(k--)
                {
                    result +=r;
                }
                i++;
            }
            else
            {
                result +=s[i];
                i++;
            }
        }
        return result;
    }
    string decodeString(string s) {
        int i =0;
        return decode(i,s);
    }
};