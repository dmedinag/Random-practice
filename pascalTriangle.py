# Given numRows, generate the first numRows of Pascal's triangle.
#
# For example, given numRows = 5,
# Return
#
# [
#      [1],
#     [1,1],
#    [1,2,1],
#   [1,3,3,1],
#  [1,4,6,4,1]
# ]

# My solution here is not the most efficient (the use of a semi-coroutine here is not really justified)
# However, it looks fancy and helps me studying for my exam in concurrency tomorrow, so... I'll use
# it as an example of how semi-coroutines work in Python

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """

        # Define a semi-coroutine (because why not?)
        def pascal(n):

            # Special Case 1: First row in Pascal Triangle
            row = [1]
            yield row # Return value and pause execution

            # Rest of rows are calculated based on Special Case 1
            for i in range(1, n):
                for j in range(len(row)-1):
                    row[j] += row[j+1]
                row.insert(0, 1)
                yield row

        # "main"

        res = [] # Initialize the returning list
        # Special Case 0: no need for call coroutine (empty list)
        if not numRows: return res

        # Regular case: Append as many rows as needed
        for line in pascal(numRows):
            res.append(line[:])
        return res
