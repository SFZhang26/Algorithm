# 454. 4Sum II

class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        result=0
        count={}
        for a in A:
            for b in B:
                if (a+b) not in count:
                    count[a+b]=1
                else:
                    count[a+b]+=1
        for c in C:
            for d in D:
                if (-c-d) in count:
                    result+=count[-c-d]
        return result
