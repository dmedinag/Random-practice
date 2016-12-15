# Problem from leetcode.com
#
# Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
#
# If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
#
# You may not alter the values in the nodes, only nodes itself may be changed.
#
# Only constant memory is allowed.
#
# For example,
#
# Given this linked list: 1->2->3->4->5
# For k = 2, you should return: 2->1->4->3->5
# For k = 3, you should return: 3->2->1->4->5

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        reversing = []
        prevNode = None
        node = head
        i = 0

        while True:
            if node is not None:

                ### 1. Get elements of the current group
                reversing.append(node)

                if i == k-1:
                    ### 2. Reverse current group when complete

                    node = node.next
                    reversing[0].next = node
                    for j in range(1, k): reversing[j].next = reversing[j-1]

                    ### 3. Update the pointer to the first node of the modified group

                    # node prior to the head of the current group will now have the head of the modified group as next
                    if prevNode != None: prevNode.next = reversing[k-1]
                    else: head = reversing[k-1] # 1st iteration will change the head instead, let's update it

                    ### 4. Prepare next iteration

                    prevNode = reversing[0] # previous 1st node in the group is now the last in the group
                    del reversing[:]        # reset the temp array for the next reversing operation
                    i = 0                   # reset counter
                    continue

                node = node.next
                i += 1
                continue
            break
        return head
