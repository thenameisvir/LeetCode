class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Step 1: Circularity ke liye pehle ek loop n-1 to 0
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            st.push(nums[i]);
        }

        // Step 2: Actual NGE calculate karne ke liye
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            else ans[i] = -1;
            st.push(nums[i]);
        }

        return ans;
    }
};
