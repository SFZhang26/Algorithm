# 6. ZigZag Conversion

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        step=0
        if numRows==1:
            return s
        
        result=""
        
        for i in range(numRows):
            j=i
            step=2*numRows-(i+1)*2
            while j<len(s):
                if (i==0) or (i==numRows-1):
                    result=result+s[j]
                    j=j+2*numRows-2
                else:
                    result=result+s[j]
                    j+=step
                    step=2*numRows-2-step
                    
        return result
