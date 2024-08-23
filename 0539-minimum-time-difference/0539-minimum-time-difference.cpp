class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (const auto& time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            int total = hours * 60 + minutes;
            v.push_back(total);
        }
        
        // Sort the time in minutes
        sort(v.begin(), v.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            minDiff = min(minDiff, v[i] - v[i-1]);
        }

        // Also consider the difference between the first and last time (across midnight)
        int firstLastDiff = v[0] + 1440 - v.back();
        minDiff = min(minDiff, firstLastDiff);

        return minDiff;
    }
};
