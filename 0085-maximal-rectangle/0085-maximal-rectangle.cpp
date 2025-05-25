class Solution {
public:
    vector<int> solve1(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < arr.size(); i++) {
            while(st.top() != -1 && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> solve2(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(st.top() != -1 && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& arr) {
        vector<int> prev = solve1(arr);
        vector<int> next = solve2(arr);

        for(int i = 0; i < next.size(); i++) {
            if(next[i] == -1) next[i] = next.size();
        }

        int maxArea = 0;
        for(int i = 0; i < arr.size(); i++) {
            int length = arr[i];
            int breadth = next[i] - prev[i] - 1;
            int temp = length * breadth;
            maxArea = max(temp, maxArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& m) {
        if(m.empty()) return 0;

        int n = m.size();
        int cols = m[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < cols; j++) {
                if(m[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
