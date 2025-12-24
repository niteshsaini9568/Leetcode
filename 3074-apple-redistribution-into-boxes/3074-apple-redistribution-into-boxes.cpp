class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());

        int sum = 0;
        for (int x : apple) sum += x;

        int c_sum = 0;
        int count = 0;

        for (int x : capacity) {
            c_sum += x;
            count++;
            if (c_sum >= sum) break;
        }

        return count;
    }
};
