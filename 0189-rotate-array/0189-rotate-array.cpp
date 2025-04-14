class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>brr(nums.size());
        int n = nums.size();
        for(int i=0;i<n;i++){
            brr[(k+i)%n] = nums[i];
        }

        nums = brr;
    }
};