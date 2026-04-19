class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(auto&interval:intervals){
            if(ans.empty()||ans.back()[1]<interval[0]){
                //no overlap
                ans.push_back(interval);
            }
            else{//overlap->merging
                ans.back()[1]=max(ans.back()[1],interval[1]);
            }
        }
            return ans;
    }
};