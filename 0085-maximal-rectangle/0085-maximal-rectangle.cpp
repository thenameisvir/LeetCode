class Solution {
   vector<int>nextSmaller(vector<int>&arr){
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
    vector<int>prevSmaller(vector<int>&arr){
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

            maxArea = max(maxArea,area);
        }


        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;

        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }

        int area =  largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                // let's update current row with previous values
                if(v[i][j]){
                    v[i][j] += v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }

            }
            area = max(area,largestRectangleArea(v[i]));

        }

        return area;


        


    }
};