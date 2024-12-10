class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // TreeNode* curr = root;

        // while (curr) {
        //     if (curr->left == NULL) {
        //         ans.push_back(curr->val);
        //         curr = curr->right;
        //     } else {
        //         TreeNode* pred = curr->left;

                
        //         while (pred->right && pred->right != curr) {
        //             pred = pred->right;
        //         }

        //         if (pred->right == NULL) {
                    
        //             pred->right = curr;
        //             curr = curr->left;
        //         } else {
                    
        //             pred->right = NULL;
        //             ans.push_back(curr->val);
        //             curr = curr->right;
        //         }
        //     }
        // }

        // return ans;


        // sbse pehle apan log ek vector banayenge 
        vector<int>ans; 
        // iske baad ab apan ek node banayenge
        TreeNode* curr = root;

        while(curr){
            if(!curr->left){
                // agar mera left null hai to cha mudaye duniya mai to chala push karne
                ans.push_back(curr->val);
                // ab iske baad idhar udhar bhi to jana padega na to mai left ko null krke aya hu
                // toh ab right me jaunga 
                curr = curr->right;
            }
            else{
                // ye jo node hai pehle ek kadam left jayegi , chalo jao
                TreeNode* pred = curr->left;
                // ab is bkl ko bhejo khub dur
                while(pred->right&&pred->right!=curr){
                    pred = pred->right;
                }

                // ab sasura check karenge ki pred ka right null hai ya nahii

                if(!pred->right){

                    pred->right = curr;
                    curr = curr->left;

                }
                else{
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }

            }
        }

        return ans;
    }
};
