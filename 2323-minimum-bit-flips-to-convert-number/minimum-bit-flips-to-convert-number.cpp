class Solution {
public:
    /*
        Approach XOR of two numbers will gives us the number of fliped bits required
        TC => O(K) XOR of two number set bits
        SC => O(1)
    */
    int minBitFlips(int start, int goal) {
        int x = start ^ goal ;
        int count =0;
        while(x)
        {
            x = x & (x-1);
            count ++;
        }
        return count;
    }
};