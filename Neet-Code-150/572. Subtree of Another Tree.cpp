//DFS within DFS
//O(NM) Time (N num of nodes in main tree, M num of nodes in subtree)
//O(N+M) Space (Caused by recursion call stack)
 class Solution {
public:
    bool checkSubTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return true;
        else if(!root || !subRoot)return false;

        return (root->val==subRoot->val) && checkSubTree(root->left,subRoot->left) && checkSubTree(root->right,subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)return true;
        else if(!root || !subRoot)return false;

        return checkSubTree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};