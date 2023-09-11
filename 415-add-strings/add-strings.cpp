class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans ="";
        int n1= num1.size()-1;
        int n2= num2.size()-1;
        int carry =0;


        while(n1>= 0 && n2>= 0){
           ans +=((num1[n1] - '0' + num2[n2] - '0'+ carry )%10 + '0');
           carry = (num1[n1] - '0' + num2[n2] - '0'+ carry)/10;
           n1--;
           n2--;
        }
        while(n1>= 0){
            ans +=  ((num1[n1] - '0' +  carry )%10+ '0');
            carry = (num1[n1] - '0' +  carry)/10;
            n1--;
        }
        while(n2>= 0){
           ans += ((num2[n2]-'0'+ carry) %10 + '0');
           carry = (num2[n2] -'0' + carry)/10;
           n2--;
        }
        if(carry>0){
            ans += '1';
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};