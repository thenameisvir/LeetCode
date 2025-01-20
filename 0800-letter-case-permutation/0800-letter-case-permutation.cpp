class Solution {
public:
    void solve(vector<string>&v,string input,string output){
        if(input.length()==0){
            v.push_back(output);
            return;
        }
        
        if(input[0]>='a'&& input[0]<='z' || input[0]>='A'&& input[0]<='Z'){
            char ch1 = tolower(input[0]);
            char ch2 = toupper(input[0]);

            input = input.substr(1);
            solve(v,input,output+ch1);
            solve(v,input,output+ch2);
        }
        else{
            char ch = input[0];
            input = input.substr(1);
            solve(v,input,output+ch);
        }

    }
    vector<string> letterCasePermutation(string s) {
        string input = s;
        vector<string>v;
        solve(v,input,"");
        return v;

    }
};