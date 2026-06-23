class Solution {
public:
    int findSum(int n){
        int sum = 0;
        while(n){
            int last = n % 10;
            n /= 10;
            sum += last;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = findSum(nums[i]);
        }
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
        return mini;
    }
};