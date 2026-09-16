class Solution {
public:
    int count (int ind , string& s , vector<int>&dp){
        if(ind == s.size()) return 1;
        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) return dp[ind];
        int one = count (ind + 1 , s , dp);
        int two = 0;
        if(ind + 1 < s.size()){
            int num = (s[ind] - '0') * 10 + (s[ind+1] - '0');
            if(num >= 10 && num <= 26){
                two = count (ind + 2 , s , dp) ;
            }
        }
        return dp[ind] = one + two;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return count(0 , s , dp);
    }
};