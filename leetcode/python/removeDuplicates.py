# 80. Remove Duplicates from Sorted Array II

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        pos=0
        
        for i in nums:
            if pos<2 or nums[pos-2]!=i:
                nums[pos]=i
                pos+=1
        return pos
