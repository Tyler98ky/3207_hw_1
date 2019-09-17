# Project Giorgios Discrete Event Simulator


* SEED 786
* INIT_TIME 0
* FIN_TIME 10000
* ARRIVE_MIN 100
* ARRIVE_MAX 2000
* QUIT_PROB 5
* CPU_MIN 5
* CPU_MAX 35
* DISK1_MIN 60
* DISK1_MAX 100
* DISK2_MIN 60
* DISK2_MAX 100

These are the initial configurations I set up for my program. This generates around 5000 events for our simulator in 
less than a second. The way my program works is primarily by utilizing a PriorityQueue and generating new events each time 
one is processed. For each one of these new events that we process through the priority queue, we create one that has an
arrival time of the `CURRENT_TIME + lengthOfProcess`. What this achieves is the perception of asynchronous tasks constantly
population our working event queue. We continue to go through and process these events and randomly assign them their destination,
whether that is to leave the CPU and quit immediately, go to disk 1 for I/O, or go to disk 2 for I/O. We then log each and every 
event that is handled by the priority queue, along with the type of task processed as well as the timestamp of when that event occurred.
Once the program counter reaches FIN_TIME, then the program will will finish all tasks that are finishing at the same time, and
then the program will terminate. Everything is output to a log.txt file and the Configuration is read from Config.txt. All 
of this is done dynamically and automatically so there isn't anything changing between program runs. This is especially relevant
when discussing the config attribute SEED, because without changing the program SEED, the output will be exactly the same every time,
minus real-world time-stamps that I've included, because the SEED determines the random number generation throughout the whole 
program. By changing the SEED, or even updating it to dynamically accept a more entropic SEED such as epoch time, you can 
obtain random results and better achieve our goal of creating a discrete event simulator. Along with manipulating things such as 
the SEED, I have tested altering all of the different config attributes to see how they affect the program. For example, by 
altering the maximum time spent on the hard disks, you can affect the totaly frequency that the hard disks' queue's are utilized.
By increasing the processing time of hard disk 1, that means that hard disk 2 will naturally be processing more data than hard disk one,
but because it's queue will be changing size more frequently, (much higher turnover), the minimum and maximum values become much more
volatile. There are obvious effects when you alter the `ARRIVE_MIN` and `ARRIVE_MAX`. The higher these two values are combined,
 the fewer events that our simulator will be able to processed in our pre-definied amount of time (FIN_TIME - INIT_TIME).
 Quit probability has the potential to affect performance greatly, but because we generally will keep the probability very low
 in order to more accurately represent real world scenarios, it doesn't make much of a significant impact. At it's lowest values,
 the program processes fewer events and the hard disks are utilized more heavily (Higher max capacity). At it's highest values, the inverse
 holds true, therefore the impact is predictable, but at scales that mimic reality, it's not extremely impactful to performance. 


 