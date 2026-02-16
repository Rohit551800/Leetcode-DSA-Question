class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        for (auto it : freq) {
            cnt[it.second]++;
        }

        for (int i = 0; i < n; i++) {
            if (cnt[freq[nums[i]]] == 1) {
                return nums[i];
            }
        }
        return -1;
    }
};