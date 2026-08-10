class Solution {
public:
    int canWeSplit(vector<int>&nums , int m){
        int n = nums.size();
        int countK = 1 , prevSum = 0;
        for(int i=0;i<n;i++){
            if(prevSum + nums[i] <= m){
                prevSum += nums[i];
            }
            else{
                countK++;
                prevSum = nums[i];
            }
        }
        return countK;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        //Bruteforce Solution
        // for(int i=low;i<=high;i++){
        //     int count = canWeSplit(nums , i);
        //     if(count <= k){
        //         return i;
        //     }
        // }

        //Optimal Solution
        while(low <= high){
            int mid = low + high >> 1;
            int count = canWeSplit(nums , mid);
            if(count <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};