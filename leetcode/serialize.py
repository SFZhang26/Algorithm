# 449. Serialize and Deserialize BST

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.result=''
        self.preOrder(root)
        return self.result
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        nums=[int(x) for x in data.split()]
        return self.helper(nums)
    
    def helper(self, nums):
        if len(nums)==0:
            return None
        value=nums[0]
        root=TreeNode(value)
        index=len(nums)
        for i in range(1,len(nums)):
            if nums[i]>value:
                index=i
                break
        root.left=self.helper(nums[1:index])
        root.right=self.helper(nums[index:])
        return root
    
    def preOrder(self, root):
        if root==None:
            return
        self.result+=(str(root.val)+' ')
        self.preOrder(root.left)
        self.preOrder(root.right)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
