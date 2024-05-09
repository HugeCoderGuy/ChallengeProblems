/**
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr & q == nullptr){
            return true;
        }
        else if ((p != nullptr & q == nullptr) |
                (p == nullptr & q != nullptr)) {
            return false;
        }
        std::queue<TreeNode*> first_tree;
        std::queue<TreeNode*> second_tree;
        first_tree.push(p);
        second_tree.push(q);
        TreeNode* first;
        TreeNode* second;
        while (!second_tree.empty()) {
            first = first_tree.front();
            first_tree.pop();
            second = second_tree.front();
            second_tree.pop();
            if (first->val != second->val) {
                return false;
            }
            if (first->left != nullptr & second->left != nullptr) {
                first_tree.push(first->left);
                second_tree.push(second->left);
            }
            else if ((first->left == nullptr & second->left != nullptr)
                     | first->left != nullptr & second->left == nullptr) {
                return false;
            }
            if (first->right != nullptr & second->right != nullptr) {
                first_tree.push(first->right);
                second_tree.push(second->right);
            }
            else if ((first->right == nullptr & second->right != nullptr)
                    | first->right != nullptr & second->right == nullptr) {
                return false;
            }
        }
        return true;
    }
};
