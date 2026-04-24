class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        // 1. Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 2. Node found, handle deletion cases:
            
            // Case 1 & 2: No child or only one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root; // Clean up memory
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root; // Clean up memory
                return temp;
            }

            // Case 3: Two children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            // Delete the successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};