//DFS within DFS
//O(NM) Time (N num of nodes in main tree, M num of nodes in subtree)
//O(N+M) Space (Caused by recursion call stack)
class Solution {
public:
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if((!root && subRoot) || (!subRoot && root))
            return false;
        else if(!root && !subRoot)
            return true;
            
        return root->val==subRoot->val && isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        
        if(isIdentical(root,subRoot))
            return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};