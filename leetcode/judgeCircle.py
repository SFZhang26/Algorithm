#  657. Judge Route Circle

class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        c = collections.Counter(moves)
        return c['U'] == c['D'] and c['L'] == c['R']
