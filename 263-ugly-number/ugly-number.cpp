class Solution {
public:
    bool isUgly(int n) {
        if( n<= 0) return false;
        if(n==1) return true;
        vector<int>factors = {2, 3 , 5};
        for(auto it :factors){
            while(n % it == 0){
                n /= it;
            }
        }
        return n == 1;
    }
};