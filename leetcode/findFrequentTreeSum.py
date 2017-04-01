# 508. Most Frequent Subtree Sum

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.dict={}
        self.helper(root)
        frequent=0
        for key in self.dict.keys():
            frequent=max(frequent,self.dict[key])
        result=[]
        for key in self.dict.keys():
            if self.dict[key]==frequent:
                result.append(key)
        return result

    def helper(self, root):
        if not root:
            return 0
        l=self.helper(root.left)
        r=self.helper(root.right)
        all=root.val+l+r
        self.dict[all]=self.dict[all]+1 if all in self.dict.keys() else 1
        return all
