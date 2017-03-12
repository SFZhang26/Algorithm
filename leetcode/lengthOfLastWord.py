# 58. Length of Last Word

class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count=0
        flag=False
        for i in s[::-1]:
            if i==' ':
                if flag:
                    return count
                else:
                    continue;
            else:
                count=count+1
                flag=True
        
        return count
