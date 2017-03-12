# 67. Add Binary

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        if len(a)<len(b):
            temp=b
            b=a
            a=temp
    
        result=""
        flag=False
        for i in range(len(b)):
            if a[len(a)-1-i]==b[len(b)-1-i]:
                if flag:
                    if a[len(a)-1-i]=='0':
                        flag=False
                    else:
                        flag=True
                    result='1'+result
                else:
                    if a[len(a)-1-i]=='0':
                        flag=False
                    else:
                        flag=True
                    result='0'+result    
            else:
                if flag:
                    result='0'+result
                else:
                    result='1'+result
                    
        if len(a)>len(b):
            for i in a[0:len(a)-len(b)][::-1]:
                if i=='1':
                    if flag:
                        result='0'+result
                        flag=True
                    else:
                        result='1'+result
                        flag=False
                else:
                    if flag:
                        result='1'+result
                    else:
                        result='0'+result
                    flag=False
        
        return '1'+result if flag else result
