# 506. Relative Ranks

class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        result=[]
        medal=["Gold Medal", "Silver Medal", "Bronze Medal"]
        rank=sorted(nums,reverse=True)
        for i in nums:
            index=rank.index(i)
            result.append(str(index+1) if index>2 else medal[index])
        return result
