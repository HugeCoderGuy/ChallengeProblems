# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        print(root)
        if root == None:
            return root
        unexplored = [root]

        while len(unexplored) > 0:
            node = unexplored.pop()
            tmp = False
            if node.left != None:
                unexplored.append(node.left)
                tmp = node.left
                if node.right == None:
                    node.left = None

            if node.right != None:
                unexplored.append(node.right)
                node.left = node.right
                if not tmp:
                    node.right = None
            
            if tmp:
                node.right = tmp

        return root
