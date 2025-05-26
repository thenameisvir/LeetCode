class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans(arr.size());
        stack<int>st;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                ans[i] = 0;
            }
            else if(arr[i]>=arr[st.top()]){
                while(!st.empty() && arr[i]>=arr[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                }
                else{
                    ans[i] = st.top()-i;
                }
            }
            else if(arr[i]<arr[st.top()]){
                ans[i] = st.top()-i;;
            }
            st.push(i);
        }
        return ans;
    }
};