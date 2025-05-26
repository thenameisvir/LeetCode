class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<double>ans(n,-1.0);
        stack<int>st;

        for(int i=arr.size()-1;i>=0;i--){
            // dekho agar car ki speed uske front bencheres se kum hai toh gadbad h
            while(!st.empty() && arr[i][1] <=arr[st.top()][1]){
                st.pop();
            }

            // yaha tak agye ho toh kch na kch toh mila hoga pakka
            while(!st.empty()){
               double time = (double)(arr[st.top()][0] - arr[i][0]) / (arr[i][1] - arr[st.top()][1]);

                if(ans[st.top()]==-1 || time<=ans[st.top()]){
                    ans[i] = time;
                    break;
                }
                else{
                    st.pop();
                }
            }

            st.push(i);
        }

        return ans;
    }
};