class Solution {
public:
    const long long mod = 1e9+7;
    int f(int ind , string &s ,vector<int>&dp){
        if(ind < 0) return 1;
        if(dp[ind] != -1) return dp[ind];

        long long ans = 2LL * f(ind -1 , s , dp);

        int prev = -1;
        for(int i = ind-1 ;i>=0;i--){
            if(s[i] == s[ind]){
                prev = i;
                break;
            }
        }

        if(prev != -1){
            ans -= f(prev-1 , s, dp);
        }

        ans = (ans+mod) % mod;

        return dp[ind] = ans;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return (f(n-1, s, dp) - 1 + mod) % mod;
    }
};