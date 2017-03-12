# 38. Count and Say

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==0:
            return ""
        
        prev="1"
        next=""
        for i in range(2,n+1):
            cur=prev[0]
            count=1
            for j in range(1,len(prev)):
                if prev[j]==cur:
                    count=count+1
                else:
                    next=next+str(count)+cur
                    cur=prev[j]
                    count=1
            next=next+str(count)+cur
            prev=next
            next=""
        
        return prev
