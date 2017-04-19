# 462. Minimum Moves to Equal Array Elements II

class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<=1:
            return 0
        nums=sorted(nums)
        mid=nums[len(nums)/2]
        return sum([abs(x-mid) for x in nums])
