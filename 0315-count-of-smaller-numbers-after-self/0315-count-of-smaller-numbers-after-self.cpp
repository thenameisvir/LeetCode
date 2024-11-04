class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0), sorted;
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Find the index where nums[i] would be inserted in the sorted array
            int pos = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            result[i] = pos;
            // Insert nums[i] in the sorted order
            sorted.insert(sorted.begin() + pos, nums[i]);
        }
        
        return result;
    }
};
