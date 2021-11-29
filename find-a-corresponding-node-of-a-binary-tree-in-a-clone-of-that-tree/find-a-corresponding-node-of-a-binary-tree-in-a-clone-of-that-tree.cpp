class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if( !original || !cloned ) return NULL;
        if( original == target ) return cloned;
        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        TreeNode* right = getTargetCopy(original->right, cloned->right, target);
        return left ? left : ( right ? right : NULL );
    }
};