# 515. Find Largest Value in Each Tree Row

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root==None:
            return []
        que=[]
        result=[]
        que.append(root)
        result.append(root.val)
        while True:
            new_que=[]
            new_val=[]
            for cur in que:
                if cur.left:
                    new_que.append(cur.left)
                    new_val.append(cur.left.val)
                if cur.right:
                    new_que.append(cur.right)
                    new_val.append(cur.right.val)
            que=new_que
            if len(que):
                result.append(max(new_val))
            else:
                break
        return result
