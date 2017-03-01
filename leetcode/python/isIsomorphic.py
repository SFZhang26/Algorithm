# 205. Isomorphic Strings

class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s)!=len(t):
            return False
        
        s2t={}
        t2s={}
        for i,j in zip(s,t):
            if s2t.get(i,'*')!='*' and s2t[i]!=j:
                return False
            else:
                s2t[i]=j
            
            if t2s.get(j,'*')!='*' and t2s[j]!=i:
                return False
            else:
                t2s[j]=i
        return True
