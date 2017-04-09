# 557. Reverse Words in a String III

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        li=[x[::-1] for x in s.split()]
        return ' '.join(li)
