class Solution {
public:
    bool canEatBanana(vector<int>&piles , int mid , int h){
        long long count = 0;
        for(int i=0;i<piles.size();i++){
            count += ceil((double)piles[i]/mid);
        }
        if(count <= h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canEatBanana(piles , mid , h)){
                ans = min(ans , mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};