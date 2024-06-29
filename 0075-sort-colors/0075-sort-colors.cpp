class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;     // Pointer for current element
        int j = 0;     // Pointer for next position of 0
        int l = nums.size() - 1; // Pointer for next position of 2
        
        while (i <= l) {
            if (nums[i] == 0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[l]);
                l--;
            } else {
                i++;
            }
        }
    }
};
