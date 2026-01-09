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
    pair<int,TreeNode*> lca(TreeNode* root){
            if(!root)return {0,NULL};
            pair<int,TreeNode*> l = lca(root->left);
            pair<int,TreeNode*> r = lca(root->right);
            int cnt1 = l.first;
            int cnt2 = r.first;
            return {max(cnt1,cnt2)+1,cnt1 == cnt2 ? root: cnt1 > cnt2 ? l.second : r.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lca(root).second;
    }
};
