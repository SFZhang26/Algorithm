# 472. Concatenated Words

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result=[]
        set_words=set(words)
        for word in words:
            n=len(word)
            dp=[0]*(n+1)
            dp[0]=1
            for i in range(n):
                if dp[i]==0:
                    continue
                for j in range(i+1,n+1):
                    if j-i<n and word[i:j] in set_words:
                        dp[j]=1
                
                if dp[n]==1:
                    result.append(word)
                    break
        
        return result
