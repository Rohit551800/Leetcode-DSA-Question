class Solution {
public:
    string minWindow(string text, string pattern) {

        if (pattern.length() > text.length()) return "";

        vector<int> count(256, 0);

        for (char ch : pattern) {
            count[ch]++;
        }

        int start = 0;
        int matched = 0;
        int minStart = 0;
        int minSize = INT_MAX;

        for (int i = 0; i < text.length(); i++) {

            count[text[i]]--;

            if (count[text[i]] >= 0) {
                matched++;
            }

            while (matched == pattern.length()) {

                if (i - start + 1 < minSize) {
                    minSize = i - start + 1;
                    minStart = start;
                }

                count[text[start]]++;

                if (count[text[start]] > 0) {
                    matched--;
                }

                start++;
            }
        }

        if(minSize == INT_MAX) return "";
        return text.substr(minStart, minSize);
    }
};
