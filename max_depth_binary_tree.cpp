/**
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int max_val_seen = 0;
        std::vector<std::tuple<TreeNode*, int>> to_visit;
        std::tuple<TreeNode*, int> curr_node_tup;
        TreeNode* curr_node;
        int depth;

        if (root->left != nullptr) {
            to_visit.push_back(std::make_tuple(root->left, 2));
            max_val_seen++;
        }
        if (root->right != nullptr) {
            to_visit.push_back(std::make_tuple(root->right, 2));
            if (max_val_seen != 1) {
                max_val_seen++;
            }
        }
        if (root->right == nullptr & root->left == nullptr) {
            return 1; 
        }
        while (!to_visit.empty()) {
            curr_node_tup = to_visit.back();
            to_visit.pop_back();
            curr_node = std::get<0>(curr_node_tup);
            depth = std::get<1>(curr_node_tup);

            if (depth > max_val_seen) {
                max_val_seen = depth;
            }
            if (curr_node->left != nullptr) {
                to_visit.push_back(std::make_tuple(curr_node->left, depth + 1));
            }
            if (curr_node->right != nullptr) {
                to_visit.push_back(std::make_tuple(curr_node->right, depth + 1));
            }
        }

        return max_val_seen;
    }
};
