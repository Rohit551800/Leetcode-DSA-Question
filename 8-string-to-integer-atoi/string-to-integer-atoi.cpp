class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        int i = 0;
        bool firstOp = false;

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') firstOp = true;
            i++;
        }


        while(i < n){
            if(s[i] >= 48 && s[i] <= 57){
                int x = s[i] - '0';

                if(ans > (INT_MAX - x) / 10){
                    return firstOp ? INT_MIN : INT_MAX;
                }
                ans = 10 * ans + x;
            }
            else{
                break;
            }
            i++;
        }
        return firstOp? -1 * ans : ans;
    }
};