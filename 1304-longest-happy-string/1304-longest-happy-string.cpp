class Info {
public:
    char val;
    int count;

    Info(char ch, int cnt) {
        this->val = ch;
        this->count = cnt;
    }
};

class compare {
public:
    bool operator()(Info a, Info b) {
        return a.count < b.count; // Max heap based on count
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, compare> pq;
        if (a > 0) pq.push(Info('a', a));
        if (b > 0) pq.push(Info('b', b));
        if (c > 0) pq.push(Info('c', c));

        string ans = "";

        while (!pq.empty()) {
            Info first = pq.top();
            pq.pop();

            // Check if the last two characters in the result are the same as the current character
            if (ans.size() >= 2 && ans[ans.size() - 1] == first.val && ans[ans.size() - 2] == first.val) {
                if (pq.empty()) break; // No alternative characters to use, stop
                Info second = pq.top();
                pq.pop();

                // Add one instance of the second character
                ans.push_back(second.val);
                second.count--;

                // Push back the second character if it still has remaining count
                if (second.count > 0) {
                    pq.push(second);
                }

                // Push the first character back into the heap for future consideration
                pq.push(first);
            } else {
                // Add up to 2 instances of the current character
                int use = min(2, first.count);
                for (int i = 0; i < use; i++) {
                    ans.push_back(first.val);
                }
                first.count -= use;

                // Push back the character if it still has remaining count
                if (first.count > 0) {
                    pq.push(first);
                }
            }
        }

        return ans;
    }
};
