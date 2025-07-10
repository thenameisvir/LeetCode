class Solution {
public:
    class Info {
    public:
        int data;
        int rowIndex;
        int colIndex;

        Info(int data, int rowIndex, int colIndex) {
            this->data = data;
            this->rowIndex = rowIndex;
            this->colIndex = colIndex;
        }
    };

    class compare {
    public:
        bool operator()(Info* a, Info* b) {
            return a->data > b->data; // min-heap
        }
    };

    void solve(vector<vector<int>>& nums, vector<int>& ans) {
        priority_queue<Info*, vector<Info*>, compare> pq;

        int maxi = INT_MIN;

        // Step 1: Push first element from each list
        for (int i = 0; i < nums.size(); i++) {
            Info* newNode = new Info(nums[i][0], i, 0);
            pq.push(newNode);
            maxi = max(maxi, nums[i][0]);
        }

        int minRange = INT_MAX;

        while (!pq.empty()) {
            Info* temp = pq.top(); pq.pop();

            int mini = temp->data;
            if (maxi - mini < minRange) {
                ans[0] = mini;
                ans[1] = maxi;
                minRange = maxi - mini;
            }

            int toprow = temp->rowIndex;
            int topcol = temp->colIndex;

            // Push next element from the same row if exists
            if (topcol + 1 < nums[toprow].size()) {
                Info* newone = new Info(nums[toprow][topcol + 1], toprow, topcol + 1);
                pq.push(newone);
                maxi = max(maxi, newone->data);
            } else {
                // No more elements in this row -> can't include all lists anymore
                break;
            }
        }
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        solve(nums, ans);
        return ans;
    }
};
