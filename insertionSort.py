#!/usr/bin/env python

def insertionSort(theSeq):

	n = len(theSeq)

	for i in xrange(1, n):
		value = theSeq[i]

		pos = i
		while pos > 0 and value < theSeq[pos - 1]:
			theSeq[pos] = theSeq[pos - 1]
			pos -= 1
		theSeq[pos] = value

if __name__ == '__main__':
	testSeq = [67, 31, 49, 31, 109, 3, 66]
	insertionSort(testSeq)
	for item in testSeq:
		print item