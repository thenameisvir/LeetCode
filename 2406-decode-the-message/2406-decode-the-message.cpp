class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        char arr[300] = {0};
        for(auto ch:key){
            if(ch!=' ' && arr[ch]==0){
                arr[ch] = start;
                start++;
            }
        }

        string ans = "";

        for(int i=0;i<message.length();i++){
            char ch = message[i];

            if(ch==' '){
                ans.push_back(' ');
            }
            else{
                char decoder = arr[ch];
                ans.push_back(decoder);
            }
        }
        return ans;
    }
};