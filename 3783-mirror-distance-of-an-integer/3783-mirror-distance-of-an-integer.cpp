class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0;
        int temp = n;   // preserve original number

        while (temp) {
            int digit = temp % 10;
            reverse = reverse * 10 + digit;
            temp = temp / 10;
        }

        return abs(n - reverse);
    }
};