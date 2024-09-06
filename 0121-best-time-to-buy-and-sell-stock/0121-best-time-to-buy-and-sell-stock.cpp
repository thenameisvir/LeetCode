class Solution {
public:
    int nikalo(vector<int>& arr,int mini,int maxi,int index,int size){
        if(index>=size){
            return maxi;
        }

        if(arr[index]<mini){
            mini = arr[index];
        }
        int cp = arr[index] - mini;

        if(cp>maxi){
            maxi = cp;
        }

        return nikalo(arr,mini,maxi,index+1,size);
    }

    int maxProfit(vector<int>& arr) {
        int mini = INT_MAX;
        int index = 0;
        int maxi = 0;
        int size = arr.size();
        int ans = nikalo(arr,mini,maxi,index,size);
        return ans;
    }
};