class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = i;
            }
        }

        // yaha tak apne map me store ho chuka hai

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(mp.find(val)!=mp.end() && mp[val]!=i){
                ans.push_back(i);
                ans.push_back(mp[val]);
                break;
            }
        }

        return ans;

    }
};