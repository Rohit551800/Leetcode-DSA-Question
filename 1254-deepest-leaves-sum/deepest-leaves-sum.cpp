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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>result;
        while(!q.empty()){
            int n = q.size();
            vector<int>ans;
            for(int i=0;i<n;i++){
                auto root = q.front();
                q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);

                ans.push_back(root->val);
            }
            result.push_back(ans);
        }
        vector<int>x = result[result.size()-1];
        int sum = 0;
        for(auto it : x){
            sum += it;
        }
        return sum;
    }
};