class SegmentTree {
public:
    vector<int> seg;
    int size;

    SegmentTree(int n) {
        size = n;
        seg.resize(4 * n, 0);
    }

    void update(int index, int value, int node, int l, int r) {
        if (l == r) {
            seg[node] = max(seg[node], value);
            return;
        }

        int mid = (l + r) / 2;
        if (index <= mid) {
            update(index, value, 2 * node + 1, l, mid);
        } else {
            update(index, value, 2 * node + 2, mid + 1, r);
        }

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    int query(int ql, int qr, int node, int l, int r) {
        if (qr < l || ql > r) return 0; // out of range
        if (ql <= l && r <= qr) return seg[node]; // total overlap

        int mid = (l + r) / 2;
        return max(query(ql, qr, 2 * node + 1, l, mid),
                   query(ql, qr, 2 * node + 2, mid + 1, r));
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Coordinate Compression
        set<int> s(nums.begin(), nums.end());
        for (int num : nums) {
            s.insert(num - k);  // for nums[i] - k range
        }

        unordered_map<int, int> compress;
        int id = 0;
        for (int val : s) {
            compress[val] = id++;
        }

        SegmentTree st(id);
        int ans = 0;

        for (int num : nums) {
            int l = num - k;
            int r = num - 1;

            int left = compress.count(l) ? compress[l] : 0;
            int right = compress.count(r) ? compress[r] : compress[num] - 1;

            int maxLIS = 0;
            if (left <= right)
                maxLIS = st.query(left, right, 0, 0, id - 1);

            int currCompressed = compress[num];
            st.update(currCompressed, maxLIS + 1, 0, 0, id - 1);

            ans = max(ans, maxLIS + 1);
        }

        return ans;
    }
};
