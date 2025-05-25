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
    int maximalRectangle(vector<vector<char>>& m) {
        vector<vector<int>>v;
        for(int i=0;i<m.size();i++){
            vector<int>temp;
            for(int j=0;j<m[i].size();j++){
                int a = m[i][j]-'0';
                temp.push_back(a);
            }
            v.push_back(temp);
        }

        int maxArea = largestRectangleArea(v[0]);
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }

            maxArea = max(maxArea,largestRectangleArea(v[i]));
        }

        return maxArea;

    }
};