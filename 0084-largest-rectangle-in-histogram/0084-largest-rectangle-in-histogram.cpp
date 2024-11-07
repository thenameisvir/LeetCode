class Solution {
public:
    vector<int>nextSmaller(vector<int>& arr){
        vector<int>ans(arr.size());

        stack<int>st;
        st.push(-1);


        for(int i=arr.size()-1;i>=0;i--){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int>prevSmaller(vector<int>& arr){
        vector<int>ans(arr.size());

        stack<int>st;
        st.push(-1);


        for(int i=0;i<arr.size();i++){
            int curr = arr[i];

            while(st.top()!=-1 && arr[st.top()]>=curr){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = nextSmaller(heights);
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i] = next.size();
            }
        }
        vector<int>prev = prevSmaller(heights);

        int maxArea = INT_MIN;

        for(int i=0;i<heights.size();i++){
            int length = heights[i];

            int width = next[i]-prev[i]-1;

            int area = length*width;

            maxArea = max(area,maxArea);
        }


        return maxArea;
    }
};