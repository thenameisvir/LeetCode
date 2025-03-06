class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        vector<int>ans;
        // brute force
        unordered_map<int,bool>vis;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(vis[arr[i][j]]){
                    ans.push_back(arr[i][j]);
                     arr[i][j]=0; 
                     
                }
                else{
                    vis[arr[i][j]] = true;
                }
            }
        }
        int count = 0;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                count++;
                sum+=arr[i][j];
            }
        }

        int sum2 = 0;
        for(int i=1;i<=count;i++){
            sum2+=i;
        }

        ans.push_back(sum2-sum);
        return ans;

        




        



    }
};