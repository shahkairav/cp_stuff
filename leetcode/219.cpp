// 219. Contains Duplicate II

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k += 1;
        multiset<int> s;
        for (int i = 0; i < min(k, (int)nums.size()); i++) {
            s.insert(nums[i]);
            if (s.count(nums[i]) > 1) return true;
        }
        if (k >= nums.size()) return false;
        for (int i = k; i < nums.size(); i++) {
            s.insert(nums[i]);
            s.erase(s.find(nums[i-k]));
            if (s.count(nums[i]) > 1) return true;
        }

        return false;
    }
};