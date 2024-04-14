/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, bool isLeft){
        if (!node) {
            return 0;
        }
        if(!node->left && !node->right){ // i.e. leaf node
            if(isLeft) return node->val;
            else return 0;
        }   
        int leftsum = dfs(node->left , true);
        int rightsum = dfs(node->right , false);
        return leftsum+rightsum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root , false);
    }
};