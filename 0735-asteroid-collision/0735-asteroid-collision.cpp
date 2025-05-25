class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++){
            int curr = arr[i];
            bool destroyed = false;
            while(!st.empty() && st.top()>0 && curr<0){
                if(abs(curr)>st.top()){
                    st.pop();
                }
                else if(abs(curr)==st.top()){
                    st.pop();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed){
                st.push(curr);
            }
        }


        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};