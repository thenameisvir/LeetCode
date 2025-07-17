class Solution {
public:
    int space(string str1, string str2){
        int n = str1.size();
        int m = str2.size();

        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);

        // space optimized me base case fill karna halka nahi hai aur na hi hum

        for(int i=0;i<=m;i++){
            prev[i] = m-i;
        }

        for(int i=n-1;i>=0;i--){
            // edit distance me main cheese
            curr[m] = n-i;
            for(int j=m-1;j>=0;j--){

                if(str1[i]==str2[j]){
                    curr[j] = prev[j+1];
                }
                else{
                    int ans1 = 1 + prev[j+1];
                    int ans2 = 1 + curr[j+1];
                    int ans3 = 1 + prev[j];

                    curr[j] = min({ans1,ans2,ans3});
                }

            }

            prev = curr;       
        }

        return prev[0];


    }
    int minDistance(string word1, string word2) {
        return space(word1,word2);
    }
};