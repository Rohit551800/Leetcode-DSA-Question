class Solution {
public:
    const int mod = 1e9 + 7;
    int f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        //Base Case
        if(j < 0) return 1;
        if(i < 0) return 0;
        //Explore all the possibilities
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 
                f(i-1 , j-1 , s , t , dp) + f(i-1 , j , s , t , dp);
        else return dp[i][j] = f(i-1 , j , s , t , dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        //Recurrence + Memoization

        // vector<vector<int>>dp(n , vector<int>(m , -1));
        // return f(n-1 , m-1 , s , t , dp);

        //Tabulation
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
        // for(int j=0;j<=n;j++){
        //     dp[j][0] = 1;
        // }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]%mod + dp[i-1][j]%mod;
        //         else dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp[n][m];

        //Space Optimization

        vector<int>prev(m+1 , 0) , curr(m+1 , 0);
        prev[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]) prev[j] = prev[j-1]%mod + prev[j]%mod;
                else prev[j] = prev[j];
            }
        }
        return prev[m];
    }
};