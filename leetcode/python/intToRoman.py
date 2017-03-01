# 12. Integer to Roman

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        relation=["","I","II","III","IV","V","VI","VII","VIII","IX",
                  "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                  "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                  "","M","MM","MMM"]
        
        result=""
        strNum=str(num)
        for i in range(len(strNum)):
            result=relation[i*10+int(strNum[len(strNum)-1-i])]+result
        
        return result
