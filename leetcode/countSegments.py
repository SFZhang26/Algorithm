# 434. Number of Segments in a String

class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(list(s.split()))
