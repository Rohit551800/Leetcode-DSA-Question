class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(ans.back()[0] <= intervals[i][0] && ans.back()[1] >= intervals[i][1]){}
            else if(ans.back()[0] >= intervals[i][0] && ans.back()[1] <= intervals[i][1]){
                ans.pop_back();
                ans.push_back(intervals[i]);
            }
            else ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};