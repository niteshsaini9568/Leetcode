class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        if(prices.size() == 0) return 0; 
        long long ans = 1;  
        long long curr = 1;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                curr++;
            } else {
                curr = 1;
            }
            ans += curr;
        }

        return ans;
    }
};
