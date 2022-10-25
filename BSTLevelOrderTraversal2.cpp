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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> sol;    //solution
        vector<int> level;          //list of nodes per level
        TreeNode *current = root;   //current node
        queue<TreeNode*> nodes;     //queue holding nodes to visit
        
        if(root == nullptr){
            return sol;
        }
        nodes.push(root);
        
        while(!nodes.empty()){
            
            //iterate throughout entire queue, which contains nodes for a 
            //respective level, assuming nodes aren't null.
            //number of nodes double every level (1,2,4,8,16,32,...)
            //total number possible nodes = 2^n-1
            for(int levelCount = nodes.size(); levelCount > 0; levelCount--){
                current = nodes.front();
                nodes.pop();
                level.push_back(current->val);
                if(current->left != nullptr){
                    nodes.push(current->left);
                }
                
                if(current-> right != nullptr){
                    nodes.push(current->right);
                }
            }
            
            if(level.size() > 0){
                sol.push_back(level);
                level.clear();
            }
        }
        
        reverse(sol.begin(), sol.end());
        return sol;
    }
};