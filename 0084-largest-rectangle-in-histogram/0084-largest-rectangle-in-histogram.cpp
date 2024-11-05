class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&arr){
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
    vector<int>prevSmallerElement(vector<int>&arr){
        vector<int>ans(arr.size());
        stack<int>st;
        st.push(-1);

        for(int i=0;i<=arr.size()-1;i++){
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
        vector<int>next = nextSmallerElement(heights);
        // make sure krna ki next me koi bhi answer -1 na ho 
        for(int i=0;i<next.size();i++){
            if(next[i]==-1){
                next[i] = next.size();
            }
        }
        vector<int>prev = prevSmallerElement(heights);

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