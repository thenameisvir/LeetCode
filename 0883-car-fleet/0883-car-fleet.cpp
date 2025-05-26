class Solution {
public:
    static bool isComp(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;  // descending sort
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {position[i], speed[i]};
        }

        sort(v.begin(), v.end(), isComp);  // descending order of position

        stack<float> st;
        for(int i = 0; i < n; i++){
            float time = (float)(target - v[i].first) / v[i].second;
            if(!st.empty() && time <= st.top()){
                // fleet mein merge ho jaayega, kuch nahi karna
                continue;
            }
            st.push(time);  // nayi fleet
        }

        return st.size();
    }
};
