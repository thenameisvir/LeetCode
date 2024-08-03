class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;

        int travelP = 0;
        int travelM = 0;
        int travelG = 0;

        int lastP = 0;
        int lastM = 0;
        int lastG = 0;

        for(int i=0;i<garbage.size();i++){
            string str = garbage[i];
            for(int j=0;j<str.length();j++){
                char ch = str[j];
                if(ch=='G'){
                    pickG++;
                    lastG = i;
                }
                if(ch=='M'){
                    pickM++;
                    lastM = i;
                }
                if(ch=='P'){
                    pickP++;
                    lastP = i;
                }
            }
        }

        for(int i=0;i<lastP;i++){
            travelP+=travel[i];
        }
        for(int i=0;i<lastM;i++){
            travelM+=travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }

        int ans = (pickP+travelP)+(pickM+travelM)+(pickG+travelG);
        return ans;
    }
};