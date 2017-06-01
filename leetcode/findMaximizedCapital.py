# 502. IPO

class Solution(object):
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        import Queue
        res = W
        que = Queue.PriorityQueue()
        pj = sorted(zip(Capital, Profits))[::-1]

        for i in range(k):
            while pj and pj[-1][0]<=res:
                que.put(-pj[-1][1])
                pj.pop()
            if not que.empty():
                res-=que.get()
            
        return res
