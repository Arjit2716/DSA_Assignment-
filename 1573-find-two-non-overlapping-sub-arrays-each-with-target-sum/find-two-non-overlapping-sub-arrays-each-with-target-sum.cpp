class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window if sum is greater than target
            while (left <= right && sum > target) {
                sum -= arr[left];
                left++;
            }

            // Carry forward the previous best
            if (right > 0)
                best[right] = best[right - 1];

            // Found a subarray [left...right]
            if (sum == target) {
                int len = right - left + 1;

                // Need a previous non-overlapping subarray.
                // Previous subarray must end before 'left'.
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Update best subarray seen so far
                best[right] = min(best[right], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};