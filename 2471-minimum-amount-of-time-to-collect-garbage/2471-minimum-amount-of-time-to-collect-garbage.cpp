class Solution {
public:
    int garbageCollection(vector<string>& arr, vector<int>& travel) {
        int pickP = 0;
        int pickM = 0;
        int pickG = 0;

        int lastP = 0;
        int lastM = 0;
        int lastG = 0;

        int travelP = 0;
        int travelM = 0;
        int travelG = 0;

        for(int i=0;i<arr.size();i++){
            string curr = arr[i];
            for(int j=0;j<curr.length();j++){
                if(curr[j]=='P'){
                pickP++;
                lastP = i;
                }
                if(curr[j]=='M'){
                pickM++;
                lastM = i;
                }
                if(curr[j]=='G'){
                pickG++;
                lastG = i;
                }
            }
        }

        for(int i=0;i<lastM;i++){
            travelM+=travel[i];
        }
        for(int i=0;i<lastG;i++){
            travelG+=travel[i];
        }
        for(int i=0;i<lastP;i++){
            travelP+=travel[i];
        }

        int ans = (pickP+pickM+pickG) + (travelP+travelM+travelG);
        return ans;
    }
};