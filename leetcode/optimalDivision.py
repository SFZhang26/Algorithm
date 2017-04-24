# 553. Optimal Division

class Solution(object):
    def optimalDivision(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums)==1:
            return str(nums[0])
        if len(nums)==2:
            return str(nums[0])+'/'+str(nums[1])
        
        return str(nums[0])+'/('+('/'.join([str(x) for x in nums[1:]]))+')'
