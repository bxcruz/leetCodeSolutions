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
void InOrderWalk(TreeNode* node, vector<TreeNode*>& vals, vector<TreeNode*>& pos){
    if(node != nullptr){
        InOrderWalk(node->left, vals,pos);
        if(!vals.empty() && node->val < vals[vals.size()-1]->val){
            pos.push_back(vals[(vals.size()-1)]);
            pos.push_back(node);
        }
        vals.push_back(node);
        InOrderWalk(node->right, vals,pos);
    }
}

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodeList;
        vector<TreeNode*> posPairs;
        InOrderWalk(root,nodeList, posPairs);
        nodeList.clear();
        TreeNode* s1 = posPairs[0];
        TreeNode* s2 = posPairs[posPairs.size()-1];
        swap(s1->val,s2->val);
    }
};
