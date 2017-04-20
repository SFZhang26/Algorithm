# 456. 132 Pattern

class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)<3:
            return False
        
        stk=[]
        c=-1e10
        for a in nums[::-1]:
            if a<c:
                return True
            else:
                while len(stk)>0 and a>stk[-1]:
                    c=stk[-1]
                    stk.pop()
                stk.append(a)
        return False
