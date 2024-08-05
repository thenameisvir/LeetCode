class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        char s = 'a';
        char arr[200] = {0};
        string str = "";
        for(auto ch:pattern){
            if(arr[ch]==0){
                arr[ch] = s;
                s++;
            }
        }

        for(auto ch:pattern){
            char decoder = arr[ch];
            str.push_back(decoder);
        }
        vector<string>final;
        for(int i=0;i<words.size();i++){
            char start = 'a';
            string str2 = "";
            char arr2[200] = {0};
            string curr = words[i];
            for(auto ch:curr){
                if(arr2[ch]==0){
                    arr2[ch] = start;
                    start++;
                }
            }

            for(auto ch:curr){
                char decoder = arr2[ch];
                str2.push_back(decoder);
            }

            final.push_back(str2);
        }
        vector<string>full_n_final;
        for(int i=0;i<final.size();i++){
            string curr = final[i];
            if(curr==str){
            full_n_final.push_back(words[i]);
            }
        }

        return full_n_final;
    }
};