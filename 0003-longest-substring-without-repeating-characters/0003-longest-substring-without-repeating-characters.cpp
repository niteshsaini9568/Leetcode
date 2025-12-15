class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int r = 0;
        int l = 0;
        int maxLength = 0;

        while (r < s.size()) {
            if (st.count(s[r])) {
                while (st.count(s[r])) {
                    st.erase(s[l]);
                    l++;
                }
            }

            st.insert(s[r]);
            r++;
            maxLength = max(maxLength, r - l);
        }

        return maxLength;
    }
};
