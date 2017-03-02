# 324. Wiggle Sort II

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        length=(len(nums)+1)/2
        nums[::2],nums[1::2]=nums[:length][::-1],nums[length:][::-1]
