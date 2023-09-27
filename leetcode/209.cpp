// 209. Minimum Size Subarray Sum

/* Approach 1 - Two Pointer approach - O(N) */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ret = INT_MAX;
        int left_ptr = 0, right_ptr = 0;
        int sum = 0;
        while (left_ptr < nums.size()) {
            while (right_ptr < nums.size() && sum < target) {
                sum += nums[right_ptr++];
            }
            if (sum >= target) {
                ret = min(ret, right_ptr - left_ptr);
            }
            sum -= nums[left_ptr++];
        }

        return ret == INT_MAX ? 0 : ret;
    }
};

/* Approach 2 - Binary Search using Prefix Sum Array - O(N log N) */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> prefix(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        
        // binary search over the suffix array for smallest interval such that s[j] - s[i] >= target
        int ret = INT_MAX;
        for (int i = nums.size(); i >= 0 && prefix[i] >= target; i--) {
            int j = distance(prefix.begin(), upper_bound(prefix.begin(), prefix.end(), prefix[i] - target));
            ret = min(ret, i - j + 1);
        }

        return ret == INT_MAX ? 0 : ret;
    }
};