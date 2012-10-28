#!/usr/bin/env python

def recBinarySearch(target, theSeq, first, last):

	if first > last:
		return False
	else:
		mid = (last + first) // 2
		if theSeq[mid] == target:
			return True
		elif target < theSeq[mid]:
			return recBinarySearch(target, theSeq, first, mid - 1)
		else:
			return recBinarySearch(target, theSeq, mid + 1, last)

if __name__ == '__main__':
	testList = [3, 1, 48, 41, 34, 19]
	testList.sort()
	print recBinarySearch(10, testList, 0, len(testList)-1)
	print recBinarySearch(41, testList, 0, len(testList)-1)