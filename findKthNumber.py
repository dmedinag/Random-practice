"""
Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.

Note: 1 ≤ k ≤ n ≤ 109.

Example:

Input:
n: 13   k: 2

Output:
10

Explanation:
The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
"""
import math
import sys

"""
Naive approach – Don't even try for a big n: generate the array and sort it alphabetically
"""
def sortStringArray(n, k):
    a = [str(i+1) for i in range(n)]
    sort = []
    for i in range(len(a)):
        sort.append(min(a))
        a[a.index(min(a))] = "z"
    return sort[k-1]

"""
Smart approach 1: calculate the value following the series
"""
def findKthNumber(n,k):
    v = 1

    i = 1

    while True:
        if i >= k: break
        # expandir si se puede
        while (10 * v <= n):
            v *= 10
            i += 1
            if i >= k: break
        if i >= k: break

        # completar el grupo de 10 hasta donde se pueda
        for j in range(9):
            if ( v + 1 > n ): break
            v += 1
            i += 1
            if i >= k: break
        if i >= k: break

        # reducir una dimensión mientras el último dígito sea 9
        while v%10 == 9: v = int(v/10)
        # añadir 1, volver a expander
        v += 1
        i += 1
        if i >= k: break

    return v

"""
Idea for Smart approach 2: calculate the value directly, from a formula in terms of k instead
(haven't had the time yet, I might come and fight it)
"""

n = sys.argv[1]
p = sys.argv[2]
print(generateSortedArray(int(n), int(p)))
