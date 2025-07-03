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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root){
            //left part not exist
            if(root->left == NULL){
                ans.push_back(root->val);
                root = root->right;
            }
            //left part exist karta hai 
            else {
                //left subTree not Traverse
                TreeNode* curr = root->left;
                while(curr->right != NULL && curr->right != root){
                    curr = curr->right;
                }
                // mtltb ye subtree abhi traverse nhi hua hai 
                if(curr->right == NULL){
                    curr->right = root;
                    root = root->left;
                }
                //already traverse
                else{
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};