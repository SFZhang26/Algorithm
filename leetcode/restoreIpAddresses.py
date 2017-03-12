# 93. Restore IP Addresses

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result=[]
        for a in range(max(1,len(s)-3*3),min(3,len(s)-3)+1):
            for b in range(max(1,len(s)-a-3*2),min(3,len(s)-2)+1):
                for c in range(max(1,len(s)-a-b-3*1),min(3,len(s)-1)+1):
                    if valid(s[0:a]) and valid(s[a:a+b]) and valid(s[a+b:a+b+c]) and valid(s[a+b+c:]):
                        result.append(s[0:a]+"."+s[a:a+b]+"."+s[a+b:a+b+c]+"."+s[a+b+c:])
        return result;

def valid(s):
        if len(s)==0 or (len(s)!=1 and s[0]=='0') or int(s)>255:
            return False
        else:
            return True
