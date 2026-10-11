class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int maxprod = nums[0];
        int minprod = nums[0];

        for(int i=1;i<n;i++){
            int c1 = nums[i];
            int c2 = maxprod * nums[i];
            int c3 = minprod * nums[i];

            maxprod = max(c1 , max(c2 , c3));
            minprod = min(c1 , min(c2 , c3));

            maxProd = max(maxProd , max(maxprod , minprod));
        }
        return maxProd;
    }
};