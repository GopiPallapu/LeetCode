class Solution {
public:
    /*
        Approach :
        iterate through all arrays from bank and count no of 1's 
        multiply it with y and add it to answer
        then swap y to x and x to 0 for next string
        TC => O(n* l) l = length of each string
        SC => O(1)
    */
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