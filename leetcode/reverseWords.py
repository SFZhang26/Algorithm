# 151. Reverse Words in a String

from functools import reduce

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words=s.split(' ')
        words=[word for word in filter(lambda x:x != '', words[::-1])]
        return reduce(lambda x,y:x+" "+y , words) if words else ""
