class Solution {  
public:  
    int rob(vector<int>& arr) {  
        if (arr.empty()) return 0;  
        if (arr.size() == 1) return arr[0];  

        int prev1 = 0; // Max amount robbed up to the previous house  
        int prev2 = 0; // Max amount robbed up to the house before the previous one  

        for (int i = 0; i < arr.size(); i++) {  
            int current = max(prev2 + arr[i], prev1); // Choose to rob current house or not  
            prev2 = prev1; // Move prev1 to prev2  
            prev1 = current; // Update prev1 to current  
        }  

        return prev1; // The last computed value is the maximum amount that can be robbed  
    }  
};