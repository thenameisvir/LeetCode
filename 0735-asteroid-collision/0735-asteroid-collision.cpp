class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            int curr = arr[i];
            bool destroyed = false;

            // Check for collision only if `curr` is negative
            while (!st.empty() && curr < 0 && st.top() > 0) {
                if (abs(curr) > st.top()) {
                    st.pop();
                } else if (abs(curr) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(curr);
            }
        }

        // Convert stack to vector using a traditional for loop
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
