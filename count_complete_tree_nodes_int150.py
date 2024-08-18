# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        else:
            first_node = root

        max_depth = 0
        while (first_node.left != None):
            max_depth += 1
            first_node = first_node.left

        if max_depth == 0:
            return 1

        nodes_at_depth = []

        unexplored = [(root, 0)]
        while len(unexplored) > 0:
            curr_node, depth = unexplored.pop()
            if curr_node.right != None:
                unexplored.append((curr_node.right, depth+1))
                if depth + 1 == max_depth:
                    nodes_at_depth.append(curr_node.right)

            if curr_node.left != None:
                unexplored.append((curr_node.left, depth+1))
                if depth + 1 == max_depth:
                    nodes_at_depth.append(curr_node.left)
            
            if depth + 1 == max_depth and (curr_node.right == None or curr_node.left == None):
                break
            
        return sum([2**i for i in range(0, max_depth)]) + len(nodes_at_depth)
