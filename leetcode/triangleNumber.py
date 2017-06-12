# 611. Valid Triangle Number

class Solution:
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        col=collections.Counter(nums)
        col.pop(0,None)
        nums=sorted(col.keys())
        
        prefix=[0]
        for k in nums:
            prefix.append(prefix[-1]+col[k])
        
        for j in range(len(nums)):
            k=len(nums)-1
            i=j
            while i>=0 and j>=i and k>=j:
                while k>j and nums[i]+nums[j]<=nums[k]:
                    k-=1
                if i<j:
                    res+=(col[nums[i]]*col[nums[j]]*(prefix[k+1]-prefix[j+1])+col[nums[i]]*col[nums[j]]*(col[nums[j]]-1)//2)
                else:
                    res+=(col[nums[i]]*(col[nums[j]]-1)*(prefix[k+1]-prefix[j+1])//2+col[nums[i]]*(col[nums[j]]-1)*(col[nums[i]]-2)//6)
                i-=1
        
        return res
