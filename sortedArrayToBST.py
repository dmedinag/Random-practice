"""
Definition for a binary tree node.
"""
import printTree

inputarray = [1, 2, 3, 4, 5, 6, 7, 8, 9]

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def sortedArrayToBST(nums):
    if not len(nums): return None
    mid = int(len(nums)/2)
    root = TreeNode(nums[ mid ])
    root.left = sortedArrayToBST( nums[:mid] )
    root.right = sortedArrayToBST( nums[mid+1:] )
    return root

printTree.printTree( sortedArrayToBST( inputarray ) )
