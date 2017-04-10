# 525. Contiguous Array

class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result=0
        index={0:-1}
        count=0
        for i in range(len(nums)):
            count=count+ (1 if nums[i]==0 else -1)
            if count in index:
                result=max(result, i-index[count])
            else:
                index[count]=i
        return result
