#!/usr/bin/env python

class stack:

	def __init__(self):
		self._theItems = list()

	def isEmpty(self):
		return len(self) == 0

	def __len__(self):
		return len(self._theItems)

	def peek(self):
		assert not self.isEmpty(), "Cannot peek at an empty stack"
		return self._theItems[-1]

	def pop(self):
		assert not self.isEmpty(), "Cannot pop from an empty stack"
		return self._theItems.pop()

	def push(self, item):
		self._theItems.append(item)
