class Solution {
public:
    int Height(TreeNode* root){
        if(root == nullptr){
            return true;
        }
        int maxdl = Height(root->left);
        int maxdr = Height(root->right);
        return max(maxdl,maxdr) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int leftcount = Height(root->left);
        int rightcount = Height(root->right);
        return abs(leftcount - rightcount) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
       
    }
};
