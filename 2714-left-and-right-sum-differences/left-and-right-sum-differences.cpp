class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum=0;
        int n=nums.size();
        for(int num:nums){
            totalSum+=num;
        }
        vector<int>ans(n);
        int leftSum=0;
        for(int i=0;i<n;i++){
           int rightSum=totalSum-leftSum-nums[i];
            ans[i]=abs(leftSum-rightSum);
            leftSum+=nums[i];    
        }
        return ans;
    }
};