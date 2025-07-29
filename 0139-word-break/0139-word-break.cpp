class Solution {
public:
    bool check(string &str,vector<string>&arr){
        for(auto i:arr){
            if(str==i){
                return true;
            }
        }

        return false;
    }
    bool solve(string&s, vector<string>& arr, int index){
        if(index==s.size()){
            return true;
        }

        string str = "";
        bool flag = false;

        for(int i=index;i<s.size();i++){
            str+=s[i];

            if(check(str,arr)){
                flag = flag || solve(s,arr,i+1);
            }
        }

        return flag;
    }
    bool wordBreak(string s, vector<string>& arr) {
        return solve(s,arr,0);
    }
};