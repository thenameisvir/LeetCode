class Solution {
public:
    void merge(vector<int>& arr, int s, int e) {
        int m = s + (e - s) / 2;
        int lenleft = m - s + 1;
        int lenright = e - m;
        int* left = new int[lenleft];
        int* right = new int[lenright];

        int k = s;
        for (int i = 0; i < lenleft; i++) {
            left[i] = arr[k];
            k++;
        }
        k = m + 1;
        for (int i = 0; i < lenright; i++) {
            right[i] = arr[k];
            k++;
        }

        // actual merge logic
        int mainindex = s;
        int leftindex = 0;
        int rightindex = 0;

        while (leftindex < lenleft && rightindex < lenright) {
            if (left[leftindex] < right[rightindex]) {
                arr[mainindex] = left[leftindex];
                leftindex++;
            } else {
                arr[mainindex] = right[rightindex];
                rightindex++;
            }
            mainindex++;
        }

        while (leftindex < lenleft) {
            arr[mainindex] = left[leftindex];
            leftindex++;
            mainindex++;
        }

        while (rightindex < lenright) {
            arr[mainindex] = right[rightindex];
            rightindex++;
            mainindex++;
        }

        delete[] left;
        delete[] right;
    }

    void mergesort(vector<int>& arr, int s, int e) {
        if (s >= e) return;

        int m = s + (e - s) / 2;

        mergesort(arr, s, m);
        mergesort(arr, m + 1, e);

        merge(arr, s, e);
    }

    vector<int> sortArray(vector<int>& arr) {
        int size = arr.size();
        mergesort(arr, 0, size - 1);
        return arr;
    }
};
