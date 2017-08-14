# 653. Two Sum IV - Input is a BST

class Solution:
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        self.nums = set()
        return self.help(root, k)
    
    def help(self, root, k):
        if root == None:
            return False
        if (k-root.val) in self.nums:
            return True
        else:
            self.nums.add(root.val)
            return self.help(root.left, k) or self.help(root.right, k)
            
