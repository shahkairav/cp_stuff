/*
Great question!

Proof:
Assume optimal solution is i* and j* and then prove by contradiction.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_water = 0;
        while (i < j) {
            max_water = max(max_water, (j-i) * min(height[i], height[j]));
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return max_water;
    }
};