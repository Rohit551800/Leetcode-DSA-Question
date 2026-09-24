class Solution {
public:
    int digitSum(int n){
        int num = 0;
        while(n > 0){
            int last = n % 10;
            n /=10;
            num += last;
        }
        return num;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i == digitSum(nums[i])) return i;
        }
        return -1;
    }
};