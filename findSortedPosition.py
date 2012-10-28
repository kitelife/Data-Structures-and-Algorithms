#!/usr/bin/env python

def findSortedPosition(theList, target):
	low = 0
	high = len(theList) - 1
	while low <= high:
		mid = (high + low) // 2
		if theList[mid] == target:
			return mid
		elif target < theList[mid]:
			high = mid - 1
		else:
			low = mid + 1

	return low