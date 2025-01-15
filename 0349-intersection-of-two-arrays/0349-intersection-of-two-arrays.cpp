class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Convert input arrays to sets
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        // Result vector
        vector<int> v;

        // Use a range-based for loop
        for (int num : s1) {
            if (s2.count(num)) { // `count` is a cleaner way to check for existence
                v.push_back(num);
            }
        }

        return v;
    }
};
