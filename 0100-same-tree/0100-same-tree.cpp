class Solution {
public:
    bool isSameTree(TreeNode* node1, TreeNode* node2) {
         if(node1 == NULL && node2 == NULL){
            return true;
        }
        // If only one of the nodes is
        // NULL, they are not identical
        if( node1== NULL || node2==NULL){
            return false;
        }
        // Check if the current nodes
        // have the same data value
        // and recursively check their
        // left and right subtrees
        return ((node1->val == node2->val)
            && isSameTree(node1->left, node2->left)
                && isSameTree(node1->right, node2->right));
    }
};