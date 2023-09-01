class Solution {
public:
    double myPower(double x , int n)
    {
        if(n == 0)return 1;
        double partial_ans = myPower(x , n/2);
        if(n%2 ==0)
            return partial_ans * partial_ans;
        else
            return partial_ans * partial_ans * x;
    }
    double myPow(double x, int n) {
        if(n<0)
        {
            return (1 / myPower(x , abs(n)));
        }
        return myPower(x , n);
    }
};