# 486. Predict the Winner

class Solution(object):
    def PredictTheWinner(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        prefix=[]
        total=0
        for i in nums:
            total+=i
            prefix.append(total)
            
        dp=[[0]*len(nums) for i in nums]
        for i in range(len(nums)):
            dp[i][i]=nums[i]
            
        for i in range(len(nums)-1):
            dp[i][i+1]=max(nums[i], nums[i+1])
            
        for length in range(2,len(nums)):
            for i in range(len(nums)-length):
                j=i+length
                chooseLeft=nums[i]+prefix[j]-prefix[i]-dp[i+1][j]
                chooseRight=nums[j]+prefix[j-1]-prefix[i]-dp[i][j-1]
                dp[i][j]=max(chooseLeft, chooseRight)
        
        return dp[0][-1]>=prefix[-1]/2+prefix[-1]%2
