class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > reach) return false; // can't move forward anymore
            reach = max(reach, i + nums[i]);
        }
        return true;
    }
};
