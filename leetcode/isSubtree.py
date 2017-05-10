# 572. Subtree of Another Tree

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        return self.isSame(s,t) or (s!=None and t!=None) and (self.isSubtree(s.left,t) or self.isSubtree(s.right,t))
    
    def isSame(self, s, t):
        if s==None or t==None:
            return s==t
        else:
            return s.val==t.val and self.isSame(s.left,t.left) and self.isSame(s.right,t.right)
