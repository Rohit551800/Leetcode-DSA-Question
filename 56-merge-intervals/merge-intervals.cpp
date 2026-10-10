class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];

            if(a <= ans.back()[1] && b <= ans.back()[1]){
                
            }
            else if(a <= ans.back()[1] && b > ans.back()[1]){
                ans.back()[1] = b;
            }
            else{
                ans.push_back({a , b});
            }
        }
        return ans;
    }
};