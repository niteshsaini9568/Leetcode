class Solution {
public:
    vector<int> findPrevSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    vector<int> findNextSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return next;
    }

    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev = findPrevSmaller(nums);
        vector<int> next = findNextSmaller(nums);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            ans = max(ans, nums[i] * width);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> oneD(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    oneD[j] += 1;
                else
                    oneD[j] = 0;
            }
            ans = max(ans, largestRectangleArea(oneD));
        }
        return ans;
    }
};
