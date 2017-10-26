# 630. Course Schedule III

class Solution:
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        courses.sort(key=lambda x: x[1])
        heap = []
        cur, res = 0, 0
        for t, d in courses:
            cur += t
            heapq.heappush(heap, -t)
            while cur > d:
                cur += heapq.heappop(heap)
            res = max(res, len(heap))
        
        return res
        
                
            
