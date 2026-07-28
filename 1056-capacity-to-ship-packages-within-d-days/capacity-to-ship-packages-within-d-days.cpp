class Solution {
public:
    bool canWeShip(vector<int>&nums , int mid , int d){
        int days = 1;
        int weight = 0;
        for(auto it : nums){
            if(weight + it > mid){
                weight = it;
                days++;
            }
            else{
                weight += it;
            }
        }
        return days <= d;
    }
    int shipWithinDays(vector<int>&nums , int d) {
        int n = nums.size();
        int limit = 0;
        for(auto it : nums){
            limit += it;
        }
        int low = *max_element(nums.begin() , nums.end()) , high = limit;
        int ans = limit;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canWeShip(nums , mid , d) == true){
                ans = mid;
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};