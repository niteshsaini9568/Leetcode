class Solution {
public:
    int minOperations(string s) {
        int operationsForPattern1 = 0;
        int n = s.size();
    
        for (int i = 0; i < n; ++i) {
            if (s[i] != "01"[i & 1]) {
                operationsForPattern1++;
            }
        }

        return min(operationsForPattern1, n - operationsForPattern1);
    }
};