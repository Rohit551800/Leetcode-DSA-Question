class Solution {
public:

    long long findPower(int mid, int k, int r) {
        long long power = 1;
        while (k--) {
            power *= mid;
            if (power > r) return r + 1;
        }

        return power;
    }
    int findLowerLimit(int l , int r, int k){
        int low = 1 , high = r;
        int lower = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long power = findPower(mid , k , r);
            if(power >= l){
                lower = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return lower;
    }
    int findUpperLimit(int l , int r , int k){
        int low = 1 , high = r;
        int upper = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long power = findPower(mid , k , r);
            if(power <= r){
                upper = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return upper;
    }
    int countKthRoots(int l, int r, int k) {
        if(l == 0 && r == 0) return 1;
        int lower = findLowerLimit(l , r , k);
        int upper = findUpperLimit(l , r , k);


        if(lower == -1 || upper == -1 || lower > upper) return 0;
        
        int ans =  upper - lower + 1;
        if(l == 0) return ans + 1;
        return ans; 
    }
};