class Solution {
public:
        bool f(int i , int j , string &s , string &t , vector<vector<int>>&dp){
        //BaseCase
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i < 0){
            if(t[j] == '*') {
            return f(i, j - 2, s, t, dp); 
        }
        return false;
        }
        //Explore All paths
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j] || t[j] == '.')return dp[i][j] = f(i-1 , j-1 , s , t ,dp);
        else if(t[j] == '*'){
            bool one = f(i , j-2 , s , t , dp);
            bool more = false;
            if(t[j-1] == s[i] || t[j-1] == '.'){
                more = f(i-1 , j , s , t , dp);
            }
            return dp[i][j] = one || more;
        }
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string t) {
        int n = s.size() , m = t.size();
        // vector<vector<int>>dp(n , vector<int>(m , -1));
        // return f(n-1 , m-1 ,s , t , dp);

        // Tabulation
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));


        //Base Case
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) {
            if (t[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2]; 
            }
        }
        // Explore all the paths
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1] || t[j-1] == '.')dp[i][j] = dp[i-1][j-1];
                else if(t[j-1] == '*'){
                    bool one = dp[i][j-2];
                    bool more = false;
                    if(t[j-2] == s[i-1] || t[j-2] == '.'){
                        more = dp[i-1][j];
                    }
                    dp[i][j] = one || more;
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};