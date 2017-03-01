# 415. Add Strings

class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        i=len(num1)
        j=len(num2)
        minLen=min(i,j)
        result=""
        flag=0
        for k in range(minLen):
            cur=int(num1[i-k-1])+int(num2[j-k-1])+flag
            result=str(cur%10) + result
            flag=cur/10
        
        if i>minLen:
            for k in range(i-minLen):
                cur=int(num1[i-minLen-k-1])+flag
                result=str(cur%10) + result
                flag=cur/10
        
        if j>minLen:
            for k in range(j-minLen):
                cur=int(num2[j-minLen-k-1])+flag
                result=str(cur%10) + result
                flag=cur/10
        
        if flag>0:
            result="1"+result;
        
        return result;

