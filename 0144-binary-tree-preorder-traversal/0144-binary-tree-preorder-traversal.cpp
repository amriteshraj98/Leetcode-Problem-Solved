class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ans.push_back(root->val); // bas yaha add kar diya 
                    root = root->left;
                }
                //already traverse
                else{
                    curr->right = NULL;
                    
                    root = root->right;
                }
            }
        }
        return ans;
    }
};