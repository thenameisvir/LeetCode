class Solution {
public:
    void createMapping(string &str){
        // create mapping
        char start = 'a';
        unordered_map<char, char> arr;

        for(auto ch: str){
            if(arr[ch]==0){
                arr[ch] = start;
                start++;
            }
        }

        // update the string
        for(int i=0;i<str.length();i++){
            str[i] = arr[str[i]];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        createMapping(pattern);

        for(string s: words){
            string temp = s;
            createMapping(temp);
            if(temp == pattern){
                ans.push_back(s);
            }
        }

        return ans;
    }
};
