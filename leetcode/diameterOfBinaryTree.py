# 543. Diameter of Binary Tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.result=0
        self.helper(root)
        return self.result
    
    def helper(self,root):
        if not root:
            return -1
        l=self.helper(root.left)+1
        r=self.helper(root.right)+1
        self.result=max(self.result,l+r)
        return max(l,r)
