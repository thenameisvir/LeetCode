class Solution {
public:

    bool kminusone(char&ch,string&ans,int k_1){
        int it = ans.size()-1;
        for(int i=0;i<k_1;i++){
            if(ch!=ans[it]) return false;
            it--;
        }
        return true;
    }
    string removeDuplicates(string s, int k) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            char&ch = s[i];
            if(ans.length()<k-1){
                ans.push_back(ch);
            }
            else{
                if(kminusone(ch,ans,k-1)){
                    for(int j=0;j<k-1;j++){
                        ans.pop_back();
                    }
                }
                else{
                    ans.push_back(ch);
                }
            }
        }

        return ans;
    }
};