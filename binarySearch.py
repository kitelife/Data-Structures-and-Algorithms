#!/usr/bin/env python

def binarySearch(theValues, target):

	low = 0
	high = len(theValues) - 1

	while low <= high:
		mid = (high + low) // 2
		if theValues[mid] == target:
			return True

		elif target < theValues[mid]:
			high = mid - 1

		else:
			low = mid + 1

	return False

if __name__ == '__main__':
	testList = [5, 2, 10, 20, 3, 1]
	testList.sort()
	print binarySearch(testList, 3)
	print binarySearch(testList, 100)
	print binarySearch(testList, 9)