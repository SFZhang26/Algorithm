# 43. Multiply Strings

class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        digits=[0]*(len(num1)+len(num2))
        for i in range(len(num1))[::-1]:
            for j in range(len(num2))[::-1]:
                cur=int(num1[i])*int(num2[j])
                digits[i+j+1]+=cur%10;
                digits[i+j]=digits[i+j]+cur/10+digits[i+j+1]/10
                digits[i+j+1]%=10
        
        result=""
        i=0
        while digits[i]==0:
            i=i+1
            if i>=len(digits):
                break
        else:
            while i<len(digits):
                result+=str(digits[i])
                i=i+1
            return result
        return "0"
        
