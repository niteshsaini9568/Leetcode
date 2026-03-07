class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1,1}, {0,1}, {1,0}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] != 0 || grid[m-1][n-1] != 0)
            return -1;

        auto isSafe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({1, {0, 0}});
        result[0][0] = 1;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if (x == m - 1 && y == n - 1) 
                return d;

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) && grid[x_][y_] == 0 && d + 1 < result[x_][y_]) {
                    result[x_][y_] = d + 1;
                    pq.push({d + 1, {x_, y_}});
                }
            }
        }

        return -1;
    }
};