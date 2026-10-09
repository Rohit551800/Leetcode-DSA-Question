class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0 , right  = 0;
        vector<int>hash(256 , 0);
        int maxi = INT_MIN;
        while(right < n){
            hash[s[right]]++;

            while(hash[s[right]] > 1){
                hash[s[left]]--;
                left++;
            }
            maxi = max(maxi ,  right - left + 1);
            right++;
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};