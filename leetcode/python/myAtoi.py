# 8. String to Integer (atoi)

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        i=0
        flag=1
        result=0
        while (i<len(str)) and(str[i]==' '):
            i=i+1
        
        if (i<len(str)) and (str[i]=='-'):
            flag=-1
            i=i+1
        elif (i<len(str)) and (str[i]=='+'):
            i=i+1
            
        while i<len(str):
            if (str[i]>='0') and (str[i]<='9'):
                result=result*10+int(str[i])
                if result>2147483647:
                    return 2147483647 if flag>0 else -2147483648
            else:
                break
            i=i+1
        
        return flag*result
