class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int low = 0 , high = n-1;

        while(low < high){
            if(!isalpha(s[low])){
                low++;
            }
            else if(!isalpha(s[high])){
                high--;
            }
            else{
                swap(s[low] , s[high]);
                low++ , high--;
            }
        }
        return s;
    }
};