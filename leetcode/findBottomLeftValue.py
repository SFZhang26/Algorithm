# 513. Find Bottom Left Tree Value

# Definition for a binary tree node.

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        que=[]
        result=0
        que.append(root)
        while len(que)>0:
            result=que[0].val
            new_que=[]
            for cur in que:
                if cur.left:
                    new_que.append(cur.left)
                if cur.right:
                    new_que.append(cur.right)
            que=new_que
        return result
