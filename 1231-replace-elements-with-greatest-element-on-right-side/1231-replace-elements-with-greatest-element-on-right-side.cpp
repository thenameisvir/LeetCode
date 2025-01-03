class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans(arr.size(),-1);
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            int num = st.top();
            if(num<arr[i]){
                st.push(arr[i]);
                ans[i] = num;
            }
            else{
                ans[i] = num;
            }
        }
        return ans;
    }
};