// class Solution {
// public:
//     int findpivot(vector<int>& arr){
//         int s = 0;
//         int n = arr.size();
//         int e = n-1;
//         while(s<=e){
//             int m = s+(e-s)/2;
//             if(m+1<n && arr[m]>arr[m+1]){
//                 return m;
//             }
//             else if(m-1>=0 && arr[m-1]>arr[m]){
//                 return m-1;
//             }
//             else if(arr[m]>=arr[s]){
//                 s = m+1;
//             }
//             else{
//                 e = m-1;
//             }

//         }
//         return -1;
//     }
//     int binary(vector<int>& arr,int s,int e,int target){
//         while(s<=e){
//             int m = s+(e-s)/2;
//             if(arr[m]==target){
//                 return m;
//             }
//             else if(arr[m]>target){
//                 e = m-1;
//             }
//             else{
//                 s = m+1;
//             }
//         }
//         return -1;
//     }
//     int search(vector<int>& arr, int target) {
//         int index = findpivot(arr);
//         int ans = -1;
//         int last = arr.size();
//         if(target>=arr[0] && target<=arr[index]){
//             ans = binary(arr,0,index,target);
//         }
//         else{
//             ans = binary(arr,index+1,last-1,target);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int findpivot(vector<int>& arr){
        int s = 0;
        int n = arr.size();
        int e = n-1;
        while(s<=e){
            int m = s + (e - s) / 2;
            if(m+1 < n && arr[m] > arr[m+1]){
                return m;
            }
            else if(m-1 >= 0 && arr[m-1] > arr[m]){
                return m-1;
            }
            else if(arr[m] >= arr[s]){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        return -1;
    }

    int binary(vector<int>& arr, int s, int e, int target){
        while(s <= e){
            int m = s + (e - s) / 2;
            if(arr[m] == target){
                return m;
            }
            else if(arr[m] > target){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if (n == 0) return -1;

        int pivot = findpivot(arr);

        // If array is not rotated
        if (pivot == -1) {
            return binary(arr, 0, n-1, target);
        }

        // If the target is the pivot element
        if (arr[pivot] == target) {
            return pivot;
        }

        // Determine which part of the array to search in
        if(target >= arr[0] && target <= arr[pivot]){
            return binary(arr, 0, pivot, target);
        }
        else{
            return binary(arr, pivot+1, n-1, target);
        }
    }
};