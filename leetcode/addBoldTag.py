# 616. Add Bold Tag in String

class Solution:
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        vec=[False]*len(s)
        for word in dict:
            start=0
            while start<len(s):
                index=s[start:].find(word)
                if index==-1:
                    break
                vec[start+index:start+index+len(word)]=[True]*len(word)
                start+=(index+1)
        begin=True
        res=''
        l='<b>'
        r='</b>'
        for i in range(len(s)):
            if vec[i]:
                if begin:
                    res+=(l+s[i])
                    begin=False
                else:
                    res+=s[i]
            else:
                if begin:
                    res+=s[i]
                else:
                    res+=(r+s[i])
                    begin=True
        
        return res if begin else res+r
            
