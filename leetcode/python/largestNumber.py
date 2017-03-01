# 179. Largest Number

from functools import reduce

class Solution:
    # @param {integer[]} nums
    # @return {string}
    def largestNumber(self, nums):
        li=list(map(lambda x:str(x), nums))
        li.sort((lambda x,y:cmp(y+x,x+y)))
        
        if len(li)==0:
            return "0"
        result=reduce(lambda x,y:x+y,li)
        if result[0]=='0':
            return "0"
        else:
            return result
