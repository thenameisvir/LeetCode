class Solution {
public:
    int compress(vector<char>& c) {
        vector<char>ans;
        int i = 0;
        while(i<c.size()){
            char curr = c[i];
            int count = 0;

            while(i<c.size()&& c[i]==curr){
                count++;
                i++;
            }

            ans.push_back(curr);

            if(count>1){
                string str = to_string(count);
                for(auto ch:str){
                    ans.push_back(ch);
                }
            }
        }

        c = ans;
        return c.size();
    }

};