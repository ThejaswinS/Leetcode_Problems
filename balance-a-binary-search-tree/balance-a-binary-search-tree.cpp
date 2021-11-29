class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        return buildTree(vec, 0, vec.size() - 1);
    }
    
    void inorder(TreeNode* root, vector<int>& vec) {
        if (root == NULL) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    
    TreeNode* buildTree(vector<int>& vec, int l, int r) {
        if (l > r) return NULL;
        if (l == r) return new TreeNode(vec[l]);
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(vec[m]);
        root->left = buildTree(vec, l, m - 1);
        root->right = buildTree(vec, m + 1, r);
        return root;
    }
};