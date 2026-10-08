class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        
        vector<int>hash(256 , 0);
        for(auto it : s){
            hash[it]++;
        }
        int count = 0;
        for(int i=0;i<256;i++){
            if(hash[i] % 2 != 0) count++;
        }
        return n - count + (count > 0  ? 1 : 0);
    }
};