#!/usr/bin/env python

def quickSort(theSeq):
	n = len(theSeq)
	recQuickSort(theSeq, 0, n-1)

def recQuickSort(theSeq, first, last):

	if first >= last:
		return
	else:
		pos = partitionSeq(theSeq, first, last)
		recQuickSort(theSeq, first, pos - 1)
		recQuickSort(theSeq, pos + 1, last)

def partitionSeq(theSeq, first, last):
	pivot = theSeq[first]
	left = first + 1
	right = last
	while left < right:
		while left < right and theSeq[left] < pivot:
			left += 1
		while right >= left and theSeq[right] >= pivot:
			right -= 1
		if left < right:
			theSeq[left], theSeq[right] = theSeq[right], theSeq[left]

	if right != first:
		theSeq[first] = theSeq[right]
		theSeq[right] = pivot
	return right

def shortQuickSort(theSeq):
	if not theSeq :
		return []
	return shortQuickSort([item for item in theSeq[1:] if item < theSeq[0]]) + theSeq[0:1] + \
		shortQuickSort([item for item in theSeq[1:] if item >= theSeq[0]])

if __name__ == '__main__':
	testList = [43, 12, 4124, 423, 48,421]
	print testList
	quickSort(testList)
	for item in testList:
		print item,
	print
	testList = [432, 312, 43, 412, 98, 90]
	print testList
	testList = shortQuickSort(testList)
	for item in testList:
		print item,
	print
