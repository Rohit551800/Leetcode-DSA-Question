/**
 * Definition for a binary tree root.
 * struct Treeroot {
 *     int val;
 *     Treeroot *left;
 *     Treeroot *right;
 *     Treeroot() : val(0), left(nullptr), right(nullptr) {}
 *     Treeroot(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treeroot(int x, Treeroot *left, Treeroot *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int,int> f(TreeNode* root) {
        if (!root) return {0, 0};
        auto [ls, lc] = f(root->left);
        auto [rs, rc] = f(root->right);
        int sum = ls + rs + root->val;
        int cnt = lc + rc + 1;
        if (sum / cnt == root->val) ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }
};