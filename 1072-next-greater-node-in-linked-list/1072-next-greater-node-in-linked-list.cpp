class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ans(v.size(), 0);
        stack<int> st; // empty stack

        for (int i = v.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= v[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }

            st.push(v[i]);
        }

        return ans;
    }
};
