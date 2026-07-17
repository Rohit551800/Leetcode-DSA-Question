class Solution {
public:
    bool canWinNim(int n) {
        bool ans = true;
        if(n %4 == 0) ans = false;

        return ans;
    }
};