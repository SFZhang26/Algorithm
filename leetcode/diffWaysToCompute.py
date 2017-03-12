# 241. Different Ways to Add Parentheses

class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        result=[]
        for i in range(len(input)):
            if input[i]=='+' or input[i]=='-' or input[i]=='*' or input[i]=='/':
                left=self.diffWaysToCompute(input[0:i])
                right=self.diffWaysToCompute(input[i+1:])
                for a in left:
                    for b in right:
                        if input[i]=='+':
                            result.append(a+b)
                        elif input[i]=='-':
                            result.append(a-b)
                        elif input[i]=='*':
                            result.append(a*b)
                        elif b!=0:
                            result.append(a/b)
        
        if len(result)==0:
            result.append(int(input))
        return result
