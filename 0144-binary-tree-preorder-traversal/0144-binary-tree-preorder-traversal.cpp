class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);    
        helper(node->left, res);
        helper(node->right, res);
    }
};