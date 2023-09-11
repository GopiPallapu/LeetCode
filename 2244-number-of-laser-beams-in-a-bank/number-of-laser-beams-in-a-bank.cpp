class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int answer =0;
        int x =0 , y = 0;
        for(int i  =0 ; i< bank.size() ; i++)
        {
            string str  =bank[i];
            for(int j =0 ;j< str.size() ; j++)
            {
                if(str[j] == '1')
                    x +=1;
            }
            if( x != 0 )
            {
                answer +=  (x * y ) ;
                y = x ;
                x = 0;
            }
        }
        return answer;

    }
};