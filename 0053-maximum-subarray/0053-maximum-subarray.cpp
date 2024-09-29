class Solution {
public:
    int answer(vector<int>& arr,int s,int e){
    
    if(s==e) return arr[s];
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;

    int m = s+(e-s)/2;

    int maxLeftSum = answer(arr,s,m);
    int maxRightSum = answer(arr,m+1,e);

    int leftBorderSum = 0, rightBorderSum = 0;
    for(int i=m;i>=s;i--){
        leftBorderSum+=arr[i];
        if(leftBorderSum>maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }

    for(int i=m+1;i<=e;i++){
        rightBorderSum+=arr[i];
        if(rightBorderSum>maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }

    int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;

    return max(crossBorderSum,max(maxLeftSum,maxRightSum));



    }
    int maxSubArray(vector<int>& arr) {
        return answer(arr,0,arr.size()-1);
    }
};