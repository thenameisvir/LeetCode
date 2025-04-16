class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            
            int a = abs(nums[i]);

            if(nums[a]<0) return abs(nums[i]);

            nums[a]*=-1;

        }

        return -1;
    }
};