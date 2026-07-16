class Solution {
public:
    // int calcGcd(int a , int b){
    //     while(b != 0){
    //         int temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int>prefixGcd(n);
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(nums[i], maxi);
        }

        sort(prefixGcd.begin() , prefixGcd.end());

        long long sum = 0;
        int left = 0 , right = n-1;

        while(left < right){
            sum += gcd(prefixGcd[left] , prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};