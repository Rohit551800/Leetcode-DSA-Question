class Solution {
public:
    bool checkPrimeOrNot(int n){
        if ( n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int totalOper = 0;
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                while(!checkPrimeOrNot(nums[i])){
                    nums[i]++;
                    totalOper += 1;
                }
            }
            else{
                while(checkPrimeOrNot(nums[i])){
                    nums[i]++;
                    totalOper += 1;
                }
            }
        }
        return totalOper;
    }
};