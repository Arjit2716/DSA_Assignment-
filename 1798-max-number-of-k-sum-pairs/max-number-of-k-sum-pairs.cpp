class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int left=0;
        int right=n-1;
        int cnt=0;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==k){
                cnt++;
            left++;
            right--;
            }  
            else if(sum<k) left++;
            else right--;
        }
        return cnt;
    }
};