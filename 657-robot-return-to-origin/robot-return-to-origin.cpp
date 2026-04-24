class Solution {
public:
    bool judgeCircle(string moves) {
        int l =0, r= 0 , u = 0, d = 0;
        int n = moves.size();
        for(int i=0;i<n;i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
            else if(moves[i] == 'U') u++;
            else d++;
        }
        int ans = abs(l - r) + abs(u - d);
        return ans == 0 ? true : false;
    }
};