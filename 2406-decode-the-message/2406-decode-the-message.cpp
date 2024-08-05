class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        int arr[300] = {0};

        for(auto ch: key){
            if(arr[ch]==0 && ch!=' '){
                arr[ch] = start;
                start++;
            }
        }

        string ans;
        for(auto ch:message){
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