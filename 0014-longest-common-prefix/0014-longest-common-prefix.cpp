class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int i = 0;
        string ans = "";
        char curr = 0;
        while(true){
            curr = 0;
            for(auto ch: strs){
                if(i>=ch.size()){
                    curr = 0;
                    break;
                }
                if(curr==0){
                    curr = ch[i];
                }
                else if(ch[i]!=curr){
                    curr = 0;
                    break;
                }
            }
            if(curr==0){
                break;
            }
            i++;
            ans.push_back(curr);
        }

        return ans;

    }
};