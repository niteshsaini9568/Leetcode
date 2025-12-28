class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int row = 0; row < n; row++){
            for(int col = m - 1; col >= 0; col--){
                if(grid[row][col] >= 0) break;
                count++;
            }
        }

        return count;
    }
};