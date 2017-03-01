# 187. Repeated DNA Sequences

class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s)<=10:
            return []
        
        dict={}
        result=[]
        for i in range(len(s)-10+1):
            if s[i:i+10] in dict:
                if dict[s[i:i+10]]:
                    result.append(s[i:i+10])
                dict[s[i:i+10]]=False
            else:
                dict[s[i:i+10]]=True
        return result
        
