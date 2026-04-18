class Solution {
public:
    int findRev(int n){
        int revNum = 0;
        while(n){
            int last = n % 10;
            n = n / 10;
            revNum = revNum * 10 + last;
        }
        return revNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {

        //Brute force solution


        // int n = nums.size();
        // int mini = INT_MAX;
        // for(int i=0;i<n;i++){
        //     int x = findRev(nums[i]);
        //     for(int j=i+1;j<n;j++){
        //         if(x == nums[j]){
        //             mini = min(mini , abs(i - j));
        //         }
        //     }
        // }
        // if(mini < n) return mini;
        // return -1;

        //Optimal Solution

        int n = nums.size();
        int mini = INT_MAX;

        unordered_map<int , int> mpp;
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
                mini = min(mini , abs(mpp[nums[i]] - i));
            }
            int rev = findRev(nums[i]);
            mpp[rev] = i;
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};