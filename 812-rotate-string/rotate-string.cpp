class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(m != n) return false;
        if(s == goal) return true;
        while(m >= 1){
            if(s != goal){
                char x = s[0];
                s.erase(0 , 1);
                s.push_back(x);
                m--;
            }
            else return true;
        }
        return false;
    }
};