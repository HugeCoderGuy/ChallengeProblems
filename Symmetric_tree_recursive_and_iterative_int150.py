"""
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# ITERATIVE SOLUTION
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        comp_nodes = []
        if root == None:
            return True

        comp_nodes.append((root.left, root.right))

        while len(comp_nodes) > 0:
            left, right = comp_nodes.pop()
            if left == None or right == None:
                if left != right:
                    return False
                else:
                    continue
            if left.val != right.val:
                return False
            else:
                comp_nodes.append((left.left, right.right))
                comp_nodes.append((left.right, right.left))

        return True

# RECURSIVE SOLUTION
class Solution:
    def isSymmetric(self, root: Optional[TreeNode], right: TreeNode=False, left: TreeNode=False) -> bool:
        if left == False or right == False:
            if root == None:
                return True
            if root.left == None or root.right == None:
                if root.left != root.right:
                    print("fuck")
                    return False
                else:
                    return True
            
            if root.left.val == root.right.val:
                out = self.isSymmetric(None, root.left, root.right)
                return out
            else:
                return False

        else:
            # Path for the two trees to be compared
            if left == None or right == None:
                if left != right:
                    return False
                else:
                    return True
            elif left.val != right.val:
                return False
            else:
                return self.isSymmetric(None, left.left, right.right) and self.isSymmetric(None, left.right, right.left)
