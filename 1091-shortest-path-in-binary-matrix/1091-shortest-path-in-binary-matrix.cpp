#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions{{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Edge case: Start or end is blocked
        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0) {
            return -1;
        }
        
        // Single cell matrix case
        if (m == 1 && n == 1) return 1;

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        queue<pair<int, int>> que;
        que.push({0, 0});
        grid[0][0] = 1; // Mark as visited by overwriting the grid

        int level = 1; // Start at level 1 because the first cell counts

        while (!que.empty()) {
            int N = que.size();
            while (N--) {
                auto curr = que.front();
                que.pop();

                int x = curr.first;
                int y = curr.second;

                // Check all 8 neighbors
                for (auto& dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_) && grid[x_][y_] == 0) {
                        // If we reached the bottom-right corner
                        if (x_ == m - 1 && y_ == n - 1) {
                            return level + 1;
                        }
                        
                        que.push({x_, y_});
                        grid[x_][y_] = 1; // Mark as visited
                    }
                }
            }
            level++;
        }
        return -1;
    }
};