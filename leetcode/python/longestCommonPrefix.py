# 14. Longest Common Prefix

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs)==0:
            return ""
        
        result=""
        for j in range(len(strs[0])):
            for i in range(1,len(strs)):
                if j>=len(strs[i]) or strs[0][j]!=strs[i][j]:
                    return result
            
            result+=strs[0][j]
        
        return result
