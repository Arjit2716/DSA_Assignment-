class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> index;
        for(int i=0;i<n;i++){
            int comp=target-nums[i];
            if(index.find(comp)!=index.end()) return {index[comp],i};
            index[nums[i]]=i;
        }
        return{};
    }
};