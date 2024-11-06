class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        stack<int> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            int curr = v[i];

            // Pop until the stack has a larger element on top or is empty
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // Set the next greater element or 0 if none exists
            v[i] = st.empty() ? 0 : st.top();

            // Push the current element onto the stack
            st.push(curr);
        }

        return v;
    }
};
