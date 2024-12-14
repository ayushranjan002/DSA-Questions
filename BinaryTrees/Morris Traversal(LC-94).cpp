class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current != nullptr) {
            if (current->left == nullptr) {
                // Visit the current node when there's no left subtree.
                result.push_back(current->val);
                current = current->right; // Move to the right subtree.
            } else {
                // Find the inorder predecessor of `current`.
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    // Establish a temporary link to the current node.
                    predecessor->right = current;
                    current = current->left;
                } else {
                    // Restore the tree structure and visit the current node.
                    predecessor->right = nullptr;
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }

        return result;
    }
};
