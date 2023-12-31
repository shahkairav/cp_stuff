class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        
        int ret = 0;
        int curr_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            ret = max(ret, prices[i] - curr_min);
            curr_min = min(curr_min, prices[i]);
        }
        return ret;
    }
};