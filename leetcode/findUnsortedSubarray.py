# 581. Shortest Unsorted Continuous Subarray

class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        copy=sorted(nums)
        i, j = 0, len(nums)-1
        while i<len(nums) and nums[i]==copy[i]:
            i+=1
        while j>=0 and nums[j]==copy[j]:
            j-=1
        return max(0,j-i+1)
