# 637. Average of Levels in Binary Tree

class Solution:
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        self.value=[]
        self.count=[]
        self.help(root, 0)
        return [ a/b for a, b in zip(self.value, self.count)]
    
    def help(self, root, level):
        if root == None:
            return
        if len(self.value)==level:
            self.value.append(root.val)
            self.count.append(1)
        else:
            self.value[level]+=root.val
            self.count[level]+=1
        self.help(root.left, level+1)
        self.help(root.right, level+1)
