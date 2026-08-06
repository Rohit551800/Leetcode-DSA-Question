class Solution {
public:
    bool checkProduct(int x , int t){
        int prod = 1;
        while(x){
            int last = x % 10;
            x /= 10;
            prod = last * prod;
        }
        if(prod % t == 0) return true;
        return false;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(checkProduct(i , t)) return i;
        }
        return -1;
    }
};