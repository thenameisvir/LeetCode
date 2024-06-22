class Solution {
public:
void merge(vector<int>& v, int s, int e) {
    int m = s + (e - s) / 2;

    int lenleft = m - s + 1;
    int lenright = e - m;

    int *left = new int[lenleft];
    int *right = new int[lenright];

    int k = s;
    for (int i = 0; i < lenleft; i++) {
        left[i] = v[k];
        k++;
    }
    k = m + 1;
    for (int i = 0; i < lenright; i++) {
        right[i] = v[k];
        k++;
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainindex = s;

    while (leftindex < lenleft && rightindex < lenright) {
        if (left[leftindex] < right[rightindex]) {
            v[mainindex] = left[leftindex];
            mainindex++;
            leftindex++;
        } else {
            v[mainindex] = right[rightindex];
            mainindex++;
            rightindex++;
        }
    }

    while (leftindex < lenleft) {
        v[mainindex] = left[leftindex];
        mainindex++;
        leftindex++;
    }
    while (rightindex < lenright) {
        v[mainindex] = right[rightindex];
        mainindex++;
        rightindex++;
    }

    delete[] left;
    delete[] right;
}

    void mergesort(vector<int>& v, int s, int e) {
    if (s >= e) return;

    int m = s + (e - s) / 2;

    mergesort(v, s, m);
    mergesort(v, m + 1, e);

    merge(v, s, e);
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = size1+size2;

        vector<int>v;
        for(int i=0;i<size1;i++){
            v.push_back(nums1[i]);
        }
        for(int i=0;i<size2;i++){
            v.push_back(nums2[i]);
        }
        int s = 0;
        int e = v.size()-1;
        int size = v.size();
        mergesort(v,s,e);
        if(size%2==0){
            int mid1 = size / 2;
        int mid2 = size / 2 - 1;
        double median = (v[mid1] + v[mid2]) / 2.0;  // Ensure floating-point division
        return median;
        }
        else{
            int mid = size / 2;
            double ok = v[mid];
            return ok;
        }

    }
};