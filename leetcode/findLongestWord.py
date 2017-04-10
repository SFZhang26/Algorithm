# 524. Longest Word in Dictionary through Deleting

class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        result=""
        for cur in d:
            if self.check(cur,s):
                if len(cur)>len(result):
                    result=cur
                elif len(cur)==len(result) and cur<result:
                    result=cur
        return result
    
    def check(self, cur, s):
        if len(cur)>len(s):
            return False
        index=0
        for c in s:
            if c==cur[index]:
                index+=1
            if index==len(cur):
                return True
        return False
