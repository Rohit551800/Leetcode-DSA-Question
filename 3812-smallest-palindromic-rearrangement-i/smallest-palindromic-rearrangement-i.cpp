class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        vector<int>freq(26 , 0);
        for(int i=0;i<n/2;i++){
            freq[s[i] - 'a']++;
        }

        string ans = "";
        for(int i=0;i<26;i++){
            while(freq[i] > 0){
                char c = i + 'a';
                ans += c;
                freq[i]--;
            }
        }
        string rem = ans;
        reverse(rem.begin() , rem.end());
        if(n%2 == 1){
            char mid = s[(n/2)];
            ans += mid + rem;
            return ans;
        }

        ans += rem;
        return ans;
    }
};