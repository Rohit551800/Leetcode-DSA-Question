class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0 , prod = 1;
        while(n){
            int last = n % 10;
            n = n / 10;
            sum = sum + last;
            prod = prod * last;
        }
        return (prod - sum);
    }
};