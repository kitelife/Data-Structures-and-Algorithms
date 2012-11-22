#!/usr/bin/env python
import random
import math
import threading

def worker(taskNum):
	# set r = 1
	global allcount, mutex
	count = 0

	for _ in xrange(taskNum):
		x = random.uniform(-1, 1)
		y = random.uniform(-1, 1)
		if math.sqrt(x**2 + y**2)<=1:
			count += 1
	mutex.acquire()
	allcount += count
	mutex.release()

def main(task_all_num, worker_num):
	global allcount, mutex
	threads = []

	allcount = 0
	mutex = threading.Lock()
	task_num = task_all_num / worker_num
	for _ in xrange(0, worker_num):
		threads.append(threading.Thread(target=worker, args=(task_num,)))

	for t in threads:
		t.start()

	for t in threads:
		t.join()

	print 'pi: ', 4.0 * allcount / task_all_num 

if __name__ == '__main__':

	TASKALLNUM = 40000000
	WORKERNUM = 40
	main(TASKALLNUM, WORKERNUM)