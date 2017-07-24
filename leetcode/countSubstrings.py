#  647. Palindromic Substrings

class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        m = [[True]*n for _ in range(n)]
        for k in range(1, n):
            for i in range(n - k):
                j = i + k
                if s[i] != s[j] or not m[i+1][j-1]:
                    m[i][j] = False
        res = 0            
        for i in range(n):
            for j in range(i, n):
                if m[i][j]:
                    res+=1
        return res
