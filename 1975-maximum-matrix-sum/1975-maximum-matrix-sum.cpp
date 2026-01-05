class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minElement = INT_MAX;
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                int val = matrix[row][col];
                if(val < 0) count++;
                sum += abs(val);
                minElement = min(minElement, abs(val));
            }
        }

        if(count % 2 == 0) return sum;
        return sum - 2LL * minElement;
    }
};
