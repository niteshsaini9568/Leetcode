class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int l = 0;
        int r = 0;
        int count = 1;

        for(int i = 0; i < n && r < n; i++){
            if(nums[l] != nums[r]){
                count++;
                nums[l+1] = nums[r];
                l++;
            }    

            r++;
        }
        return count;
    }
}; 