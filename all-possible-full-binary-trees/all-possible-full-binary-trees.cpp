class Solution {
public:
    unordered_map<int, vector<TreeNode *>>mp;
    
    void createTrees(vector<TreeNode *>&leftNodes, vector<TreeNode *>&rightNodes, vector<TreeNode *>&vec)
    {
        for(int i=0;i<leftNodes.size();i++)
        {
            for(int j=0;j<rightNodes.size();j++)
            {
                TreeNode *root=new TreeNode();
                root->left=leftNodes[i];
                root->right=rightNodes[j];
                vec.push_back(root);
            }
        }
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *>vec;
        if(mp.find(n)!=mp.end())
            return mp[n];
        if(n==1)
        {
            TreeNode *root=new TreeNode();
            vec.push_back(root);
        }
        for(int i=1;i<=n-1;i=i+2)
        {
            vector<TreeNode *>leftNodes=allPossibleFBT(i);
            vector<TreeNode *>rightNodes=allPossibleFBT(n-1-i);
            createTrees(leftNodes, rightNodes, vec);
        }
        mp[n]=vec;
        return vec;
    }
};