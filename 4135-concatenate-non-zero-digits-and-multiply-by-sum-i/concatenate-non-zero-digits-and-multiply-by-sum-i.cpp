class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        int m = s.size();
        string x = "";
        int sum = 0;

        for(int i=0;i<m;i++){
            int a = s[i] - '0';
            if( a != 0){
                x += s[i];
                sum += a;
            }
        }

        long long res = 1LL*stoi(x) * 1LL*sum;
        return res;
    }
};