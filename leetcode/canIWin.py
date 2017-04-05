# 464. Can I Win

class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """
        if maxChoosableInteger>=desiredTotal:
            return True
        if (1+maxChoosableInteger)*maxChoosableInteger/2<desiredTotal:
            return False
        
        self.occur={}
        return self.helper(range(1,maxChoosableInteger+1),desiredTotal)
    
    def helper(self, nums, target):
        strNums=str(nums)
        if strNums in self.occur:
            return self.occur[strNums]
        if len(nums)>0 and nums[-1]>=target:
            return True
        for i in range(len(nums)):
            if not self.helper(nums[:i]+nums[i+1:],target-nums[i]):
                self.occur[strNums]=True
                return True
        self.occur[strNums]=False
        return False
