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
    int search(vector<int>& inorder,int size,int num){
        for(int i=0;i<size;i++){
            if(inorder[i]==num) return i;
        }

        return -1;
    }
    TreeNode* construct(vector<int>& postorder, vector<int>& inorder,int& preIndex,int inStart,int inEnd,int size){
        
        // Simple question hai complex mat banao bs out of bound conditions check karo tum 
        // base case k naam par
        if(preIndex>=size || inStart>inEnd){
            return NULL;
        }

        // ek case solve kardo , ab yaha tk agye ho toh iska mtlb Node milgyi hogi , element me 
        // dalkr laga dalo

        int element = postorder[preIndex];// Index ka dhyan rkhna 

        preIndex++; // isko increment krna mt bhulna


        // position nikal lo
        int position = search(inorder,size,element);


        // Create a new Node
        TreeNode* root = new TreeNode(element);


        // ab tumko kch nahi krna hai bs recursion ko apply kardo
        root->right = construct(postorder,inorder,preIndex,position+1,inEnd,size);
        root->left = construct(postorder,inorder,preIndex,inStart,position-1,size);
        


        return root;


    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        std::reverse(postorder.begin(), postorder.end());
        int preIndex = 0;
        int inStart = 0;
        int inEnd = size-1;
        // Recursion pr bharosa rakho
        TreeNode* root = construct(postorder,inorder,preIndex,inStart,inEnd,size);
        return root;
    }
};