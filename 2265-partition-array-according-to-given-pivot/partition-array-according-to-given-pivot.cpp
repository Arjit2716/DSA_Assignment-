class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>s,e,g;
        for(int num:nums){
            if(num<pivot) s.push_back(num);
            else if(num==pivot) e.push_back(num);
            else g.push_back(num);
        }
        vector<int>ans;
        for(int x:s) ans.push_back(x);
        for(int x:e) ans.push_back(x);
        for(int x:g) ans.push_back(x);

        return ans;
    }
};