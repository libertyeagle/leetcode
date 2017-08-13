# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    traversal = list()

    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        Solution.traversal = list()
        if root is None:
            return []
        else:
            self.travel(root, 0)
            return Solution.traversal[::-1]

    def travel(self, x, level):
        if len(Solution.traversal) <= level:
            Solution.traversal.append(list([x.val]))
        else:
            Solution.traversal[level].append(x.val)
        if not (x.left) is None:
            self.travel(x.left, level + 1)
        if not (x.right) is None:
            self.travel(x.right, level + 1)
