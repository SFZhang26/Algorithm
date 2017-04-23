# 563. Binary Tree Tilt

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTilt(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.result=0
        self.helper(root)
        return self.result
    
    def helper(self, root):
        if root==None:
            return 0
        left=self.helper(root.left)
        right=self.helper(root.right)
        self.result+=abs(left-right)
        return left+right+root.val
