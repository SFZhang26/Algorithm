# 530. Minimum Absolute Difference in BST

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.vec=[]
        self.inorder(root)
        result=self.vec[1]-self.vec[0]
        for i in range(1,len(self.vec)-1):
            result=min(result,self.vec[i+1]-self.vec[i])
        return result
    
    def inorder(self, root):
        if root==None:
            return
        self.inorder(root.left)
        self.vec.append(root.val)
        self.inorder(root.right)
