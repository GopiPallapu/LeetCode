class Solution {
public:
    int fib(int n) {
        double goldenMean = (1 + sqrt(5))/2;
        double goldenNum = (1-sqrt(5))/2;

        return (pow(goldenMean,n) - pow(goldenNum,n))/sqrt(5);
    }
};