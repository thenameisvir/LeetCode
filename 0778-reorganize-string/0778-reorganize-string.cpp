#include <string>
#include <queue>
#include <vector>
using namespace std;

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
    string reorganizeString(string s) {
        int freq[26] = {0};
        // Count frequency of all characters in the string
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            freq[ch - 'a']++;
        }

        // Push all characters into a max heap
        priority_queue<Info, vector<Info>, compare> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(Info(i + 'a', freq[i]));
            }
        }

        string ans = "";
        while (pq.size() > 1) {
            Info first = pq.top();
            pq.pop();
            Info second = pq.top();
            pq.pop();

            ans.push_back(first.val);
            first.count--;
            ans.push_back(second.val);
            second.count--;

            if (first.count > 0) {
                pq.push(first);
            }
            if (second.count > 0) {
                pq.push(second);
            }
        }

        // Handle the case where one element is left
        if (pq.size() == 1) {
            Info last = pq.top();
            pq.pop();

            if (last.count > 1) {
                // Not possible to reorganize
                return "";
            }
            ans.push_back(last.val);
        }

        return ans;
    }
};
