#!/usr/bin/env python

class ListNode :
	def __init__(self, data):
		self.data = data
		self.next = None

def traversal(head):
	curNode = head
	while curNode is not None:
		print curNode.data
		curNode = curNode.next

def unorderedSearch(head, target):
	curNode = head
	while curNode is not None and curNode.data != target:
		curNode = curNode.next
	return curNode is not None

def prependingNode(head, data):
	newNode = ListNode(data)
	newNode.next = head
	head = newNode

def removeNode(head, target):
	predNode = None
	curNode = head
	while curNode is not None and curNode.data != target:
		predNode = curNode
		curNode = curNode.next

	if curNode is not None:
		if curNode is head:
			head = curNode.next
		else:
			predNode.next = curNode.next