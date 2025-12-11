class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Maps to store min/max boundaries for x values at a given y, 
        // and min/max boundaries for y values at a given x.
        map<int, int> min_x_at_y;
        map<int, int> max_x_at_y;
        map<int, int> min_y_at_x;
        map<int, int> max_y_at_x;

        // Pass 1: Find all boundaries
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // Update min/max x for this y coordinate
            if (min_x_at_y.find(y) == min_x_at_y.end() || x < min_x_at_y[y]) {
                min_x_at_y[y] = x;
            }
            if (max_x_at_y.find(y) == max_x_at_y.end() || x > max_x_at_y[y]) {
                max_x_at_y[y] = x;
            }

            // Update min/max y for this x coordinate
            if (min_y_at_x.find(x) == min_y_at_x.end() || y < min_y_at_x[x]) {
                min_y_at_x[x] = y;
            }
            if (max_y_at_x.find(x) == max_y_at_x.end() || y > max_y_at_x[x]) {
                max_y_at_x[x] = y;
            }
        }

        int covered_count = 0;

        // Pass 2: Check each building if it is strictly interior (covered)
        for (const auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            // A building is covered if it is strictly greater than the min 
            // and strictly less than the max in both dimensions (x and y).
            bool has_left   = x > min_x_at_y[y];
            bool has_right  = x < max_x_at_y[y];
            bool has_below  = y > min_y_at_x[x];
            bool has_above  = y < max_y_at_x[x];

            if (has_left && has_right && has_below && has_above) {
                covered_count++;
            }
        }

        return covered_count;
    }
};