class Solution {
public:
    vector<int>findLast (int num){
        vector<int>ans;
        while(num){
            int last = num % 10;
            num /= 10;
            ans.push_back(last);
        }
        return ans;
    }
    int maximum69Number (int num) {
        vector<int>ans = findLast(num);
        reverse(ans.begin() , ans.end());

        int res = 0;
        bool first = false;
        for(auto it : ans){
            if(it == 6 && first == false){
                res = res*10 + 9;
                first = true;
            }
            else{
                res = res * 10 + it;
            }
        }
        return res;
    }
};