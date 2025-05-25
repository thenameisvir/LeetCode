class Solution {
public:
    vector<int>solve1(vector<int>& arr){
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while(st.top()!=-1 && arr[i]<=arr[st.top()]){
                st.pop();
            }
        ans[i] = st.top();
        st.push(i);
        }
        return ans;
    }
    vector<int>solve2(vector<int>& arr){
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=-1 && arr[i]<=arr[st.top()]){
                st.pop();
            }
        ans[i] = st.top();
        st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int>prev = solve1(arr);
        vector<int>next = solve2(arr);

        int maxArea = INT_MIN;
        // ek special condition hoti hai yaha par 
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i] = next.size();
            }
        }

        for(int i=0;i<arr.size();i++){
            int length = arr[i];
            int breadth = next[i]-prev[i]-1;
            int area = length*breadth;

            maxArea = max(maxArea,area);
        }

        return maxArea;

    }
};