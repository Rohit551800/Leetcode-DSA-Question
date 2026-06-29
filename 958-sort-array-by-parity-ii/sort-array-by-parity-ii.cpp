class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        // vector<int>even;
        // vector<int>odd;

        // for(int i=0;i<n;i++){
        //     if(nums[i] % 2 == 0) even.push_back(nums[i]);
        //     else odd.push_back(nums[i]);
        // }
        // for(int i=0;i<n;i++){
        //     if(i%2 == 0) nums[i] = even[i/2];
        //     else nums[i] = odd[(i-1)/2];
        // }
        // return nums;



        int i = 0 , j = 1;

        while(i < n && j < n){
            if(nums[i] % 2 == 0) i += 2;
            else if(nums[j] % 2 == 1) j+= 2;
            else {
                swap(nums[i] , nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};