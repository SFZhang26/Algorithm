# 635. Design Log Storage System

class LogSystem(object):

    def __init__(self):
        self.base_year = 2000
        self.gra = ['Year', 'Month', 'Day', 'Hour', 'Minute', 'Second']
        self.kv = []

    def put(self, id, timestamp):
        """
        :type id: int
        :type timestamp: str
        :rtype: void
        """
        li = [int(x) for x in timestamp.split(':')]
        rank = self.get_rank(li)
        self.kv.append((rank, id))

    def retrieve(self, s, e, gra):
        """
        :type s: str
        :type e: str
        :type gra: str
        :rtype: List[int]
        """
        # sorted(self.kv, key=lambda x: x[0])
        li1 = [int(x) for x in s.split(':')]
        li2 = [int(x) for x in e.split(':')]
        pos = self.gra.index(gra)
        li2[pos] += 1
        for i in range(pos+1, len(li1)):
            li1[i] = 0
            li2[i] = 0
        rank1 = self.get_rank(li1)
        rank2 = self.get_rank(li2)
        res = []
        for (rank, val) in self.kv:
            if rank >= rank1 and rank < rank2:
                res.append(val)
        return res
    
    def get_rank(self, li):
        rank = (li[0] - self.base_year)*13*32*24*60*60 \
            + li[1]*32*24*60*60 \
            + li[2]*24*60*60 \
            + li[3]*60*60 \
            + li[4]*60 \
            + li[5]
        return rank


# Your LogSystem object will be instantiated and called as such:
# obj = LogSystem()
# obj.put(id,timestamp)
# param_2 = obj.retrieve(s,e,gra)
