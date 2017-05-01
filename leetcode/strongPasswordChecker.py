# 420. Strong Password Checker

class Solution(object):
    def strongPasswordChecker(self, s):
        """
        :type s: str
        :rtype: int
        """
        con2=3
        if any(i>='a' and i<='z' for i in s):
            con2-=1
        if any(i>='A' and i<='Z' for i in s):
            con2-=1
        if any(i>='0' and i<='9' for i in s):
            con2-=1
        
        i=2
        replace=0
        cur=0
        one,two=0,0
        while i<len(s):
            if s[i-2]==s[i-1] and s[i-1]==s[i]:
                cur=3
                i+=1
                while i<len(s) and s[i-1]==s[i]:
                    cur+=1
                    i+=1
                replace+=cur/3
                if cur%3==0:
                    one+=1
                elif cur%3==1:
                    two+=1
            else:
                i+=1
        
        if len(s)<6:
            return max(con2, 6-len(s))
        if len(s)<=20:
            return max(con2, replace)
        else:
            delete=len(s)-20
            replace-=min(delete,one)
            replace-=min(max(delete-one,0), two*2)/2
            replace-=max(delete-one-two*2,0)/3
            return max(con2, replace)+delete
            
                
