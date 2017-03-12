# 105. Construct Binary Tree from Preorder and Inorder Traversal

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder)>0:
            index=inorder.index(preorder[0])
            root=TreeNode(preorder.pop(0))
            root.left=self.buildTree(preorder[0:index],inorder[0:index])
            root.right=self.buildTree(preorder[index:],inorder[index+1:])
            return root
