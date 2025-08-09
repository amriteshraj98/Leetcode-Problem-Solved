class Solution {
public:
    TreeNode* findLastChild(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastChild = findLastChild(root->left);
        lastChild->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) {
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else{ // root->val <= key
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};