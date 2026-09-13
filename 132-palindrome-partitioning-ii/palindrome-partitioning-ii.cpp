class Solution {
public:
    // bool isPalindrome(string s){
    //     int left = 0 ,right = s.size()-1;
    //     while(left < right){
    //         if(s[left] != s[right]) return false;
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }
    int func(int ind , int size , string &s ,  vector<vector<bool>> &pal , vector<int>&dp){

        if(ind == size) return 0;
        if(dp[ind] != -1) return dp[ind];
        int minCost = INT_MAX;
        string temp = "";
        for(int j=ind ; j < size; j++){
            temp += s[j];
            if(pal[ind][j]){
                int cost = 1 + func(j + 1 , size , s , pal , dp);
                minCost = min(minCost , cost);
            }
        }
        return dp[ind] = minCost;
    }
    int minCut(string s) {
        int n = s.size() ;
        vector<int>dp(n , -1);

        vector<vector<bool>> pal(n, vector<bool>(n, false));
         // Precompute palindrome 
        for (int i = n - 1; i >= 0; i--) { 
            for (int j = i; j < n; j++) { 
                if (s[i] == s[j] && (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                } 
            } 
        }
        return func ( 0 , n , s , pal ,dp) - 1;
    }
};