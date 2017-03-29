# 538. Convert BST to Greater Tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.add=0
        self.help(root)
        return root
        
    def help(self, root):
        if root==None:
            return;
        self.help(root.right)
        root.val+=self.add
        self.add=root.val
        self.help(root.left)
