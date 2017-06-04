# 560. Subarray Sum Equals K

class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums)==0:
            return 0
        
        res=0
        n=len(nums)
        m={}
        m[0]=1
        total=0
        for i in range(n):
            total+=nums[i]
            if total-k in m:
                res+=m[total-k]
            if total in m:
                m[total]+=1
            else:
                m[total]=1
        return res
        
