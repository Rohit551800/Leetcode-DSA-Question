class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>hash (26 , 0);
        int n = s.size();
        int left = 0 , right = 0;
        int maxLen = -1;
        while(right < n){
            if(hash[s[right] - 'a'] < 2){
                maxLen = max(maxLen , right - left + 1);
                hash[s[right] - 'a']++;
                right++;
            }
            else{
                hash[s[left] - 'a']--;
                left++;
            }
        }
        return maxLen;
    }
};