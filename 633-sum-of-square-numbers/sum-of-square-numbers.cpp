class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0 , j = sqrt(c);
        while(i<=j){
            long long squareSum = (i*i) + (j*j);
            if(squareSum > c) j -= 1;
            else if(squareSum < c) i += 1;
            else return true;
        }
        return false;
    }
};