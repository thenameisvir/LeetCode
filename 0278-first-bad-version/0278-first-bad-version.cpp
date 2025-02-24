// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 0;
        int e = n-1;
        int m = s+(e-s)/2;
        while(s<=e){
            if(isBadVersion(m)){
                e = m-1;
            }
            else{
                s = m+1;
            }
            m = s+(e-s)/2;
        }

        return s;
    }
};