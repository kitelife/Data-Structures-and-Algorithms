#!/usr/bin/env python

def selectionSort(theSeq):

	n = len(theSeq)

	for i in xrange(n-1):
		smallest = theSeq[i]
		smallestIndex = i
		for j in xrange(i+1, n):
			if theSeq[j] < smallest:
				smallest = theSeq[j]
				smallestIndex = j
		if smallestIndex != i:
			theSeq[i], theSeq[smallestIndex] = theSeq[smallestIndex], theSeq[i]

if __name__ == '__main__':
	testSeq = [32, 15, 27, 48, 100, 2]
	selectionSort(testSeq)

	for item in testSeq:
		print item