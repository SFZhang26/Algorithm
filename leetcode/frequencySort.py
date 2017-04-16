# 451. Sort Characters By Frequency

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        count=[0]*256
        for ch in s:
            count[ord(ch)]+=1
        return ''.join(sorted(sorted(s),key=lambda x:count[ord(x)], reverse=True))
        
