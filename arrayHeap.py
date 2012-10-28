#!/usr/bin/env python

from myArray import Array

class MaxHeap:

	def __init__(self, maxSize):
		self._elements = Array(maxSize)
		self._count = 0

	def __len__(self):
		return self._count

	def capacity(self):
		return len(self._elements)

	def add(self, value):
		assert self._count < self.capacity(), "Cannot add to a full heap."
		self._elements[self._count] = value
		self._count += 1
		self._siftUp(self._count - 1)
	# Extract the maximum value from the heap
	def extract(self):
		assert self._count > 0, "Cannot extract from an empty heap."
		value = self._elements[0]
		self._count -= 1
		self._elements[0] = self._elements[self._count]
		self._siftDown(0)
		return value

	def _siftUp(self, ndx):
		if ndx > 0:
			parent = ndx // 2
			if self._elements[ndx] > self._elements[parent]:
				self._elements[ndx], self._elements[parent] = self._elements[parent], self._elements[ndx]
				self._siftUp(parent)

	def _siftDown(self, ndx):
		left = 2 * ndx + 1
		right = 2 * ndx + 2
		largest = ndx
		if left < self._count and self._elements[left] >= self._elements[largest] :
			if right < self._count and self._elements[right] > self._elements[left]:
				largest = right
			else:
				largest = left
		elif right < self._count and self._elements[right] >= self._elements[largest]:
			largest = right

		if largest != ndx :
			self._elements[ndx], self._elements[largest] = self._elements[largest], self._elements[ndx]
			self._siftDown( largest )

def simpleHeapSort(theSeq):

	n = len(theSeq)
	heap = MaxHeap(n)

	for item in theSeq:
		heap.add(item)

	for i in range(n-1, -1, -1):
		theSeq[i] = heap.extract()

if __name__ == '__main__':
	testList = [42, 32, 31, 90, 40, 54, 23]
	for item in testList:
		print item,
	print
	simpleHeapSort(testList)
	for item in testList:
		print item,