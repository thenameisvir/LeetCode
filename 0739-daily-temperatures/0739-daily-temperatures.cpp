class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size(),0);

        stack<int>st;

        for(int i=0;i<temperatures.size();i++){
            int curr = temperatures[i];

            while(!st.empty() && curr>temperatures[st.top()]){
                ans[st.top()] = i-st.top();
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};