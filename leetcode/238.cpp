// 238. Product of Array Except Self

/* Most Efficient Solution - Single pass and O(1) extra memory */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            ret[i] *= prefix;
            ret[n-i-1] *= suffix;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
        }

        return ret;
    }
};