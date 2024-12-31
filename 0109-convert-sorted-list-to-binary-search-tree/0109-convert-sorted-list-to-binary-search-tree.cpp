/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* okayokay(vector<int>arr,int s,int e){
        // base case
        if(s>e) return NULL;

        int m = s+(e-s)/2;
        TreeNode* root = new TreeNode(arr[m]);

        root->left = okayokay(arr,s,m-1);
        root->right = okayokay(arr,m+1,e);

        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        while(head){
            int a = head->val;
            arr.push_back(a);
            head = head->next;
        }
        int s = 0;
        int e = arr.size()-1;
        // int m = s+(e-s)/2;

        return okayokay(arr,s,e);
    }
};