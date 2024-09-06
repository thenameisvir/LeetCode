class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int min_profit = INT_MAX;
        int max_profit = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<min_profit){
                min_profit = arr[i];
            }

            int current_profit = arr[i] - min_profit;

            if(current_profit>max_profit){
                max_profit = current_profit;
            }
        }

        return max_profit;
    }
};