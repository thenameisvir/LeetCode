class Solution {
public:
    int binary(vector<int>& arr,int s,int e,int target){
        while(s<=e){
            int m = s+(e-s)/2;
            if(arr[m]==target){
                return m;
            }
            else if(arr[m]>target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return -1;
    }
    int exponential_search(vector<int>& arr, int target){
        int n = arr.size()-1;
        if(arr.size()==0) return -1;
        if(arr[0]==target) return 0;
        if(arr[n]==target) return n;


        int index = 1;
        while(index<arr.size() && arr[index]<=target){
            index*=2;
        }
        return binary(arr,index/2,min(index,n),target);
    }
    int search(vector<int>& arr, int target) {
        return exponential_search(arr,target);
    }
};