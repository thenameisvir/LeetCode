class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(mp.find(val)!=mp.end()){
                mp[val]++;
            }
            if(mp.find(val)==mp.end()){
                mp[val] = 1;
            }

        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(mp[val]==1) return val;

        }

        return -1;
    }
};