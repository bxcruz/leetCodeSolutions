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

//Traverse BST in order and record all leaf nodes
void InOrder(TreeNode* node, vector<TreeNode*>& list, vector<int>& listVal){
    
    if(node != nullptr){
        InOrder(node->left, list, listVal);
        if(node->left == nullptr && node->right == nullptr){
            list.push_back(node);
            listVal.push_back(node->val);
        }
        
        InOrder(node->right, list, listVal);   
    }
}

//Traverse BST in order and remove all nodes found in the leaf node list
void InOrderRemove(TreeNode* node, vector<TreeNode*>& list, vector<TreeNode*>::iterator& it){
    
    if(node != nullptr){
        InOrderRemove(node->left, list, it);
        
        /*
        *   check to see if a node's left and right children contained in the leaf node list.
        *   if they are, remove that node from the list.
        *   if a node is not a leaf node, ignore that node and continue checking all nodes in
        *   BST in an In-Order Treewalk.
        */
        
        if((it = std::find (list.begin(), list.end(), node->left)) != list.end()){
            node->left = nullptr;
        }
        if((it = std::find (list.begin(), list.end(), node->right)) != list.end()){
            node->right = nullptr;
        }
        InOrderRemove(node->right, list, it);   
    }
}

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        //obvious case where size of BST = 0
        if(root == nullptr){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> solution; 
        vector<TreeNode*> nodeList;                 //pointer vector to leaf nodes. eventually contains ptrs to all nodes in BST
        vector<int> leafList;                       //integer vector to values of leaf nodes
        std::vector<TreeNode*>::iterator it;        //iterator for finding occurrences of leaf nodes
        TreeNode* grabber;                          //used to verify that our last remaining node is the root
        
        InOrder(root, nodeList, leafList);          //first run-through of BST, grabbing first iteration of leaves
        
        //while we can traverse a non-empty BST
        while(!nodeList.empty()){
            InOrderRemove(root,nodeList, it);
            solution.push_back(leafList);
            grabber = nodeList[nodeList.size()-1];  //grab last element from nodeList. nodeList contains ptrs to leaf nodes
            
            /*
            *   compare value to see if it is the root, with should be the very last "leaf" node.
            *   comparing pointers vs comparing integer values of a node is a better approach in case
            *   duplicate values held by a node are used. (ex: root and another node both having the value 2)
            */
            
            if(root == grabber){                    
                break;                                 
            }
            leafList.clear();
            InOrder(root, nodeList, leafList);
        }
        return solution;
    }
};