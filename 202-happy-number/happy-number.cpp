class Solution {
public:
    int sumOfSquare(int n){
        int sum = 0;
        while(n){
            int last = n % 10;
            n = n /10;
            sum += last * last;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n == 1) return true;
        int slow = n , fast = n;
        while(fast != 1){
            slow = sumOfSquare(slow);
            fast = sumOfSquare(fast);
            fast = sumOfSquare(fast);

            if(slow == fast && slow != 1) return false;
        }
        return true;
    }
};