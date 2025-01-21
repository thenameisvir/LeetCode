class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int ans = 0;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second > 1){
                ans = i->first;
            }
        }

        return ans;
    }
};