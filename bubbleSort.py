#!/usr/bin/env python

def bubbleSort(theSeq):

	n = len(theSeq)

	for i in xrange(n-1):
		swapCount = 0
		for j in xrange(n-1-i):
			if theSeq[j] > theSeq[j+1]:
				swapCount += 1
				theSeq[j], theSeq[j+1] = theSeq[j+1], theSeq[j]
		if not swapCount:
			print "Repeat count : %s"%(i+1)
			break



if __name__ == '__main__':
	testSeq = [3,4,1,100,90,76,1000]
	bubbleSort(testSeq)

	for item in testSeq:
		print item