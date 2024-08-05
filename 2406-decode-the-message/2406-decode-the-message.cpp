class Solution {
public:
    string decodeMessage(string key, string message) {
        char s = 'a';
        char arr[300] = {0};
        for(auto ch:key){
           if(ch!=' '&& arr[ch]==0){
             arr[ch] = s;
             s++;
           }
        }

        string ans;
        for( auto ch: message){
            
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