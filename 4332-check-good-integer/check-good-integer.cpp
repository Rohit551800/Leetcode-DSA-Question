class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0;
        int squareSum = 0;

        while(n){
            int last = n % 10;
            n = n / 10;
            digitSum += last;
            squareSum += last * last;
        }

        if(abs(squareSum - digitSum) >= 50) return true;
        return false;
    }
};