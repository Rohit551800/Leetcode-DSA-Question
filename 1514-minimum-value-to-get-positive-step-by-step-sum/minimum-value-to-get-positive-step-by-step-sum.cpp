class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini = 0;
        int preSum = 0;
        for(auto it : nums){
            preSum += it;
            mini = min(mini , preSum);
        }
        return abs(mini - 1);
    }
};