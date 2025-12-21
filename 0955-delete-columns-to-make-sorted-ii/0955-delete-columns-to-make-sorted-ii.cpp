class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;
        vector<bool> alreadySorted(n-1, false);

        for(int col = 0; col < m; col++){
            bool deleted = false;
            for(int row = 1; row < n; row++){
                if (!alreadySorted[row - 1] && strs[row - 1][col] > strs[row][col]){
                    count++;
                    deleted = true;
                    break;
                }
            }
            if(deleted) continue;
            for(int i = 0; i < n-1; i++){
                alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
            }
        }

        return count; 
    }
};