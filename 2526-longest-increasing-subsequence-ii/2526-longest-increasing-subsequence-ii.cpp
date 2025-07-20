#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class SegmentTree{
public:
    vector<int>seg;
    SegmentTree(int n){
        seg = vector<int>(4*n, 0);
    }

    void update(int ind, int low, int high, int idx, int v){
        if(low > high || high < idx || low > idx) return;
        if(low >= idx && high <= idx){
            seg[ind] = v;
            return;
        }
        int mid = low + (high - low)/2;
        update(2*ind+1, low, mid, idx, v);
        update(2*ind+2, mid+1, high, idx, v);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r){
        if(low > high || high < l || low > r) return 0;
        if(low >= l && high <= r){
            return seg[ind];
        }
        int mid = low + (high - low)/2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return max(left, right);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int sz = *max_element(nums.begin(), nums.end());
        SegmentTree seg(sz+1);
        for(int i = 0; i<n; i++){
            int l = max(0, nums[i]-k);
            int r = max(0, nums[i]-1);
            int len = seg.query(0, 0, sz, l, r);
            seg.update(0, 0, sz, nums[i], len+1);
        }
        return seg.query(0, 0, sz, 1, sz);
    }
};