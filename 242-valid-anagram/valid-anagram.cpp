class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash1(26 , 0);
        vector<int>hash2(26 , 0);
        for(auto it : s){
            hash1[it - 'a']++;
        }
        for(auto it: t){
            hash2[it - 'a']++;
        }

        return hash1 == hash2;
    }
};