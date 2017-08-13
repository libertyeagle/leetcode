# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    num = 0

    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        Solution.num=0
        if root is None:
            return 0
        self.treetravel(root, 1)
        return Solution.num

    def treetravel(self, x, level):
        if (x.left is None) and (x.right is None):
            Solution.num = max(Solution.num, level)
            return

        if not x.left is None:
            self.treetravel(x.left, level + 1)

        if not x.right is None:
            self.treetravel(x.right, level + 1)
