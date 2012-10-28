#!/usr/bin/env python

from lliststack import Stack

#first method
def printListStack(head):

	s = Stack()
	curNode = head
	while curNode is not None:
		s.push(curNode.data)
		curNode = curNode.next
	while not s.isEmpty():
		item = s.pop()
		print item

#second method
def printList(node):
	if node is not None:
		printList(node.next)
		print node.data

