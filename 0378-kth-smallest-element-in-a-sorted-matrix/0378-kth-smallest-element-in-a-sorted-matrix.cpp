class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(matrix, mid, n) >= k) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }

private:
    int countLessEqual(vector<vector<int>>& matrix, int target, int n) {
        int count = 0;
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= target) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return count;
    }
};