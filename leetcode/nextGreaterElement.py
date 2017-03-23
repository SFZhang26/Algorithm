# 496. Next Greater Element I

class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        index={}
        result=[]
        for i in range(len(nums)):
            index[nums[i]]=i
        for cur in findNums:
            re=-1
            for j in nums[index[cur]+1:]:
                if j>cur:
                    re=j
                    break
            result.append(re)
        return result
