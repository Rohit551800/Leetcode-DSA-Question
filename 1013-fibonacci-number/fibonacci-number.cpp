class Solution {
public:
    int fib(int n) {
        int secprev = 0 , prev = 1;
        int curr;
        if(n <= 1) return n;
        for(int i=2;i<=n;i++){
            curr = prev + secprev;
            secprev = prev;
            prev = curr;
        }
        
        return prev;
    }
};