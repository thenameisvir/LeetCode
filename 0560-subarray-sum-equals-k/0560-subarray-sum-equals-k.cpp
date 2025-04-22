class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count  =  0;
         for(int i=0;i<arr.size();i++){
           int sum = 0;
           for(int j=i;j<arr.size();j++){
            //    if(arr[j]==0) return true;
               sum+=arr[j];
               if(sum==k) count++;
           }
       }

       return count;
    }
};