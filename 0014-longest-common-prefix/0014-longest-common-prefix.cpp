class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string ans = "";
        while(true){
            char current = 0;
            for(auto str:strs){
                if(i>=str.size()){
                    current = 0;
                    break;
                }
                if(current==0){
                    current = str[i];
                }
                else if(current!=str[i]){
                    current = 0;
                    break;
                }
            }
            if(current==0){
                break;
            }
            i++;
            ans.push_back(current);
        }
        return ans;
    }
};