# 520. Detect Capital

class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if word.lower()==word or word.upper()==word or (word[0].upper()+word[1:].lower())==word:
            return True
        else:
            return False
