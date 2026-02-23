class Solution {
public:
    bool check(int n, vector<int> &cnt) {
        vector<int> temp(10, 0);
        while(n > 0) {
            temp[n % 10]++;
            n /= 10;
        }
        return temp == cnt;
    }

    bool isDigitorialPermutation(int n) {
        int pelorunaxi = n;

        vector<int> cnt(10, 0);
        while(n > 0) {
            cnt[n % 10]++;
            n /= 10;
        }

        if(check(1, cnt)) return true;
        if(check(2, cnt)) return true;
        if(check(145, cnt)) return true;
        if(check(40585, cnt)) return true;

        return false;
    }
};