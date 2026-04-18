class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int num = n;
        while(n > 0){
            int last = n % 10;
            n = n / 10;
            rev = (rev * 10) + last;
        }
        return abs(rev - num);
    }
};