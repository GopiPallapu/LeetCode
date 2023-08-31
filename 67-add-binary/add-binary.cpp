class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size()-1;
        int n2 = b.size()-1;
        int carry =0;
        string result ="";
        while(n1 >=0 || n2>=0 || carry==1)
        {
            if(n1>=0)
            {
                carry +=a[n1]-'0';
                n1--;
            }
            if(n2>=0)
            {
                carry +=b[n2]-'0';
                n2--;
            }
            result +=((carry%2 +'0'));
            carry /=2;   
        }
        reverse(result.begin() , result.end());
        return result;
    }
};