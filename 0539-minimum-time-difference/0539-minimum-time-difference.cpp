class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>v;
        for(int i=0;i<timePoints.size();i++){
            string time = timePoints[i];
            int hours = std::stoi(time.substr(0,2));
            int minutes = std::stoi(time.substr(3,2));

            int total = hours*60 + minutes;

            v.push_back(total);
        }
        sort(v.begin(),v.end());

        int mindiff = INT_MAX;
        for(int i=1;i<v.size();i++){
            mindiff = min(mindiff, v[i] - v[i-1]);
        }

        int first = (v[0] + 1440) - v.back();
        mindiff = min(mindiff,first);
        return mindiff;
    }
};