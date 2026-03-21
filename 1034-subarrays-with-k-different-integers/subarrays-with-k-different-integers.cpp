class Solution {
public:
int helperFunc(vector<int>nums , int k){
    int n = nums.size();
        int count = 0 , right = 0 , left = 0;
        unordered_map<int , int > freq ;

        while(right < n){
            if(freq[nums[right]] == 0) k--;

            freq[nums[right]]++;

            while(k < 0){
                freq[nums[left]]--;
                if(freq[nums[left]] ==0){
                    freq.erase(nums[left]);
                    k++;
                }
                left++;
            }

            count += (right -left + 1);
            right++;
        }
        return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helperFunc(nums , k) - helperFunc(nums , k-1);
    }
};