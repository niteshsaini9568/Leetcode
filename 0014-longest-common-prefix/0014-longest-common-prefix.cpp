class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = "";
        int col_size = strs[0].length();

        for (auto &x : strs) {
            col_size = min(col_size, (int)x.length());
        }

        for (int col = 0; col < col_size; col++) {
            for (int row = 0; row < strs.size() - 1; row++) {
                if (strs[row][col] != strs[row + 1][col]) {
                    return ans;
                }
            }
            ans += strs[0][col];
        }

        return ans;
    }
};
