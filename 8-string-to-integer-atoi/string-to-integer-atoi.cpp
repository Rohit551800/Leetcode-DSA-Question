class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long ans = 0;
        int i = 0;
        int firstOp = 1;

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') firstOp = -1;
            i++;
        }


        while(i < n){
            if(s[i] >= 48 && s[i] <= 57){
                int x = s[i] - '0';
                ans = 10 * ans + x;

                if( firstOp * ans >= INT_MAX) return INT_MAX;
                if( firstOp * ans <= INT_MIN) return INT_MIN;
            }
            else{
                break;
            }
            i++;
        }
        return (firstOp == -1 )? -1 * ans : ans;
    }
};