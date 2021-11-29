class Solution {
public:
    void inorder(vector<int> &vec,TreeNode *root){
        if(!root)
            return;
        
        inorder(vec,root->left);
        vec.push_back(root->val);
        inorder(vec,root->right);
    }
    
    vector<int> merge(vector<int> vec1,vector<int> vec2){
        vector<int> res;
        int i=0,j=0;
        while(i<vec1.size() && j<vec2.size()){
            if(vec1[i]<vec2[j]){
                res.push_back(vec1[i]);
                i++;
            }
            else{
                res.push_back(vec2[j]);
                j++;
            }
        }
        while(i<vec1.size())
        {
            res.push_back(vec1[i]);
            i++;
        }
        while(j<vec2.size())
        {
            res.push_back(vec2[j]);
            j++;
        }
        return res;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec;
        vector<int> vec2;
        inorder(vec,root1);
        inorder(vec2,root2);
        return merge(vec,vec2);
    }
};