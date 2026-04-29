class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;

        // Step 1: Flatten the grid
        for (auto& row : grid)
            for (int val : row)
                nums.push_back(val);

        // Step 2: Feasibility check (must be FULLY done before anything else)
        int rem = nums[0] % x;
        for (int num : nums) {
            if (num % x != rem)
                return -1;
        }

        // Step 3: Sort to find median
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        // Step 4: Count operations
        int ops = 0;
        for (int num : nums)
            ops += abs(num - median) / x;

        return ops;
    }  // ← this closing brace was missing
};