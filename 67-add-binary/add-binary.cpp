class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int carry = 0;
        string s="";
        while(n > 0 || m > 0 || carry == 1){
            int sum = carry;
            if(n > 0){
                sum += a[n-1] - '0';
                n--;
            }
            if(m>0){
                sum += b[m-1] -'0';
                m--;
            }
            s += (sum%2) + '0';
            carry = sum / 2;
        }
        reverse(s.begin() , s.end());
        return s;
    }
};