class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            // sabse pehle index nikalke lao abs karke dhyan rkhna bhulna mt
            int index = abs(nums[i]);
            
            // ab check karo jaha aaye ho vo negative toh nahi hai
            if(nums[index]<0) return index;

            // agar vo negative nahi tha aur return nhi ho paya toh usko minus kardo

            nums[index]*=-1;
        }

        return -1;

    }
};