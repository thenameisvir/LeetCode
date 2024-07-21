class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        int i = 0;
        int j = 1;
        int count = 0;
        set<pair<int,int>>ans;
        while(j<arr.size()){
        if(arr[j]-arr[i]==k){
            ans.insert({arr[i],arr[j]});
            i++;
            j++;
        }
        else if(arr[j]-arr[i]>k){
            i++;
        }
        else{
            j++;
        }
        if(i==j) j++;
        }
        return ans.size();
    }
};