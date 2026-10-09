class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size() , m = p.size();
        vector<int>index;
        vector<int>hash1(26 , 0);
        vector<int>hash2(26 , 0);
        for(auto it : p){
            hash2[it - 'a']++;
        }

        int left = 0 , right = 0;
        while(right < n){
            hash1[s[right] - 'a']++;
            if(right - left + 1 == m){
                if(hash1 == hash2) index.push_back(left);
                hash1[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return index;
    }
};