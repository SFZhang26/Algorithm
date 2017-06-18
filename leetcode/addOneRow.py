# 623. Add One Row to Tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def addOneRow(self, root, v, d):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        if d==1:
            root_new=TreeNode(v)
            root_new.left=root
            return root_new
        else:
            self.recur(root, v, d, 1)
            return root
    
    def recur(self, root, v, d, cur):
        if cur<d-1:
            if root.left:
                self.recur(root.left, v, d, cur+1)
            if root.right:
                self.recur(root.right, v, d, cur+1)
        else:
            l=TreeNode(v)
            r=TreeNode(v)
            l.left=root.left
            r.right=root.right
            root.left=l
            root.right=r
