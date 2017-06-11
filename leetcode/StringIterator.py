# 604. Design Compressed String Iterator

class StringIterator(object):

    def __init__(self, compressedString):
        """
        :type compressedString: str
        """
        cs=compressedString
        self.li=[]
        self.count=[]
        i=0
        while i<len(cs):
            if cs[i].isalpha():
                self.li.append(cs[i])
                i+=1
                start=i
                while i<len(cs) and cs[i].isdigit():
                    i+=1
                self.count.append(int(cs[start:i]))
                
        self.index=0
        self.cur=0

    def next(self):
        """
        :rtype: str
        """
        if self.index>=len(self.li):
            return ' '
        res=self.li[self.index]
        self.cur+=1
        if self.cur==self.count[self.index]:
            self.index+=1
            self.cur=0
        return res
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.index!=len(self.li)
            


# Your StringIterator object will be instantiated and called as such:
# obj = StringIterator(compressedString)
# param_1 = obj.next()
# param_2 = obj.hasNext()
