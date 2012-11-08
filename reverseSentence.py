#!/usr/bin/env python
#coding: utf-8

def reverseSentence(someStr):
	strPartList = someStr.split(' ')
	reverseList = list()
	for word in strPartList:
		reverseList.insert(0, word)
	return " ".join(reverseList)

if __name__ == '__main__':
	someStr = 'Hello World! My name is Xiayf'
	print someStr
	print reverseSentence(someStr)