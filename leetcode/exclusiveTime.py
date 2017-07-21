# 636. Exclusive Time of Functions

class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        res = [0] * n
        cur = []
        last_time = 0
        last_action = 1
        for log in logs:
            detail = log.split(':')
            id = int(detail[0])
            action = detail[1]
            time = int(detail[2])
            if len(cur) == 0:
                cur.append(id)
                last_time = time
            if len(cur) > 0:
                pos = cur[-1]
                res[pos] += (time - last_time)
                last_time = time
                if action == 'start':
                    cur.append(id)
                    if last_action == 0:
                        res[pos] -=1
                    last_action = 1
                else:
                    cur.pop()
                    res[pos] += last_action
                    last_action = 0
        return res
