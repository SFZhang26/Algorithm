# 139. Word Break

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        dp=[False]*(len(s)+1)
        dp[0]=True
        for i in range(1,len(dp)):
            for j in range(i):
                if s[j:i] in wordDict and dp[j]:
                    dp[i]=True
                    break
        return dp[-1]
