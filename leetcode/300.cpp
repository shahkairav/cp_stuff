// 300. Longest Increasing Subsequence


/* Approach 1 - Dynamic Programming - O(N^2)  */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/* Approach 2 - Divide and Conquer - O(N * log N) */
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();

        ret.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > ret.back()) ret.push_back(nums[i]);
            else {
                int low = distance(ret.begin(), lower_bound(ret.begin(), ret.end(), nums[i]));
                ret[low] = nums[i];
            }
        }

        return ret.size();
    }
};