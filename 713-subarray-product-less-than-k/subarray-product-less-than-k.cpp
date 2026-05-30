class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        //Brute force solution having TC = O(n^3)
        // int n = nums.size();
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         long long mul = 1;
        //         for(int k=i;k<=j;k++){
        //             mul *= nums[k];
        //         }
        //         if(mul < x) count++;
        //         else break;
        //     }
        // }
        // return count;

        //Optimal Solution
        if(k <= 1) return 0;
        int n = nums.size();
        int count = 0;
        long long product = 1;
        int left =0 , right = 0;
        while (right < n){
            product = product * nums[right];

            while(product >= k){
                product /= nums[left];
                left++;
            }
            count += right -left + 1;
            right++;
            
        }
        return count;
    }
};