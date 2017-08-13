# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		transPort=0;
		currentNode=ListNode(0)
		root=currentNode
		while l1 or l2 or transPort:
			addVal1=0
			addVal2=0
			if l1:
				addVal1=l1.val
				l1=l1.next
			if l2:
				addVal2=l2.val
				l2=l2.next
			transPort, currPos=divmod(addVal1 + addVal2 + transPort, 10)
			currentNode.next=ListNode(currPos)
			currentNode=currentNode.next
		return root.next
				