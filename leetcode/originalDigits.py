# 423. Reconstruct Original Digits from English

class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        number=[0]*10
        asc=[0]*128
        
        for c in s:
            asc[ord(c)]+=1
        number[0]=asc[ord('z')]
        number[2]=asc[ord('w')]
        number[4]=asc[ord('u')]
        number[6]=asc[ord('x')]
        number[8]=asc[ord('g')]
        number[3]=asc[ord('h')]-number[8]
        number[5]=asc[ord('f')]-number[4]
        number[7]=asc[ord('v')]-number[5]
        number[1]=asc[ord('o')]-number[0]-number[2]-number[4]
        number[9]=asc[ord('i')]-number[5]-number[6]-number[8]
        return ''.join([str(i)*number[i] if number[i]>0 else "" for i in range(10)])
        
        
