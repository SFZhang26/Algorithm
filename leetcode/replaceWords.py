# 648. Replace Words

class Solution:
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        li = sentence.split()
        for i in range(len(li)):
            for k in dict:
                if li[i].startswith(k):
                    li[i] = k
        return ' '.join(li)
