class Solution {
public:
    bool f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        //BaseCase
        if(i<0){
            while(j >= 0){
                if(t[j] != '*') return false;
                j--;
            }
        }
        if(i<0 && j<0) return true;
        if(j<0) return false;
        //Explore All paths
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || t[j] == '?')return dp[i][j] = f(i-1 , j-1 , s , t ,dp);
        else if(t[j] == '*')return dp[i][j] = f(i,j-1 ,s , t , dp)||f(i-1, j, s, t,dp);
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string t) {
        int n = s.size() , m = t.size();
        //Recursion + Memoization

        // vector<vector<int>>dp(n , vector<int>(m , -1));
        // return f(n-1 , m-1 ,s , t , dp);

        //Tabulation
        vector<vector<bool>>dp(n+1 , vector<bool>(m+1 , false));

        //Base case
        dp[0][0] = true;

        for(int j = 1; j <= m; j++){
            if(t[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
        }
        // Explore all the paths

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1] || t[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(t[j-1] == '*')dp[i][j] = dp[i][j-1]|| dp[i-1][j] ;
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};