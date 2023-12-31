// 169. Majority Element

/* Approach 1 - Partial Sort */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    }
};

/* Approach 2 - Moore Voting Algorithm */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int majority;
        for(int num : nums) {
            if (!counter) majority = num;
            counter += (num == majority ? 1 : -1);
        }

        return majority;
    }
};