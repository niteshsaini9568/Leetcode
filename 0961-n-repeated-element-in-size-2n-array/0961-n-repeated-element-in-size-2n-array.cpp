class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        for (auto &x : mp) {
            if (x.second > 1) return x.first;
        }

        return -1;
    }
};
