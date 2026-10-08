class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        int start = -1;

        for(int i=0;i<n;i++){
            int left = i ,  right  = i;
            while(left >= 0 &&  right < n && s[left] == s[right]){
                int len = right - left + 1;
                if(len > ans){
                    ans = len;
                    start = left;
                }
                left--;
                right++;
            }

            left = i , right = i + 1;
            while(left >=0 && right < n && s[left] == s[right]){
                int len = right - left + 1;
                if(len > ans){
                    ans = len;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start , ans);
    }
};