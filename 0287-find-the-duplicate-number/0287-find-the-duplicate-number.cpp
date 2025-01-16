class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            // first take out the index
            int index = abs(nums[i]);
            if(nums[index]<0) return index;

            nums[index]*=-1;
        }

        return -1;
    }
};