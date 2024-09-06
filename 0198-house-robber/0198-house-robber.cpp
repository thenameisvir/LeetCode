class Solution {
public:
    int chori(vector<int>& arr,int prev1,int prev2,int index){
        if(index>=arr.size()){
            return prev1;
        }

        int current = max(arr[index] + prev2,prev1);
        prev2 = prev1;
        prev1 = current;

        return chori(arr,prev1,prev2,index+1);


    }
    int rob(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        if(arr.empty()) return 0;
        int prev1 = 0;
        int prev2 = 0;
        int index = 0;
        int ans = chori(arr,prev1,prev2,index);
        return ans;
    }
};