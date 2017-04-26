# 503. Next Greater Element II

class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result=[-1]*len(nums)
        stk=[]
        for i in range(len(nums))*2:
            while len(stk)>0 and nums[stk[-1]]<nums[i]:
                result[stk[-1]]=nums[i]
                stk.pop()
            stk.append(i)
        
        return result
