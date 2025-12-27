class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat[0].size();
        int m = mat.size();
        int start = 0, end = m*n - 1;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(mat[mid/n][mid%n] > target){
                end = mid - 1;
            }else if (mat[mid/n][mid%n] < target){
                start = mid + 1;
            }else{
                return true;
            }
        }

        return false;
    }
};