class Solution {
public:
    bool canShip(int mid , int days , vector<int>&weights){
        int carry = 0;
        int countD = 0;
        for(int i=0;i<weights.size();i++){
            if(carry + weights[i] <= mid){
                carry += weights[i];
            }
            else{
                countD ++;
                carry = weights[i];
            }
        }
        if(carry) countD++;
        if(countD <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int total = 0;
        for(auto it : weights){
            total += it;
        }
        int low = *max_element(weights.begin() , weights.end());//bcoz isse chota lenge toh max weight ko abhi shift hi nahi kr paenge
        int high = total;
        int ans = total;
        while(low <= high){
            int mid = low +(high - low)/2;
            if(canShip(mid , days , weights)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};