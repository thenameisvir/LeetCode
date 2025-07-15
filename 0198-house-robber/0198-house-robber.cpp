class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int next = nums[n-1];                  // DP[i+2]
        int curr = max(nums[n-2], nums[n-1]);  // DP[i+1]

        for(int i = n-3; i >= 0; i--) {
            int pick = nums[i] + next;         // include current
            int skip = curr;                   // exclude current
            int temp = max(pick, skip);        // DP[i]

            next = curr;
            curr = temp;
        }

        return curr;
    }
};
