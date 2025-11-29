class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto i : nums){
            ans += i;
        }

        return ans % k;
    }
};