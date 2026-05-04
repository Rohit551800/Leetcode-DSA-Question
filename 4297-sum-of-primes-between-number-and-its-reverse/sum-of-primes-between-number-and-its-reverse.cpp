class Solution {
public:
    int findRev(int n){
        int rev = 0;
        while(n){
            int last = n % 10;
            n = n/10;
            rev = rev * 10 + last;
        }
        return rev;
    }
    bool checkPrime(int n){
        if(n== 1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev = findRev(n);
        int sum = 0;
        if(rev > n){
            for(int i=n;i<=rev;i++){
                if(checkPrime(i) == true){
                    sum += i;
                }
            }
        }
        else{
            for(int i=rev;i<=n;i++){
                if(checkPrime(i) == true){
                    sum += i;
                }
            }
        }
        return sum;
    }
};