class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        unordered_map<int , int>ans;
        int count = 0;
        for(int i=0;i<n;i++){
            if(ans[password[i]] == 1){}
            else{
                if(password[i] >= 'a' && password[i] <= 'z') count += 1;
                else if(password[i] >= 'A' && password[i] <= 'Z') count += 2;
                else if(password[i] >= '0' && password[i] <= '9') count += 3;
                else count += 5;
                ans[password[i]] = 1;
            }
        }
        return count;
    }
};