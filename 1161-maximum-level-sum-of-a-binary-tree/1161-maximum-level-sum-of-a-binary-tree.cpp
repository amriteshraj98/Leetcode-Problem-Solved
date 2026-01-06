class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root->left==NULL && root->right ==NULL) return 1;
        queue<TreeNode*>q;
        q.push(root);
        int maxsum = INT_MIN;
        int level = 0;
        int maxlevel = 0;
        while(!q.empty()){
            int len = q.size();
            int sum = 0;
            for(int i = 0 ; i < len ; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
            
           if(maxsum < sum){
            maxsum = sum;
            maxlevel = level;
           }
            
        }
        return maxlevel;
    }
};