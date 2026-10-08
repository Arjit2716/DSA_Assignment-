class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        vector<int>ans(n);

        while(left<=right){

            if(nums[left]>nums[right]){
                ans[right-left]=nums[left]*nums[left];
                left++;
            }
            else{
               ans[right-left]=nums[right]*nums[right];
            right--; 
            } 
        }
        
sort(ans.begin(),ans.end());
        return ans;
    }
};