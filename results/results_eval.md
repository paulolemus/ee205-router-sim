# basic config log
The results of this log are as expected. queues all process packets only slightly
slower than the rate at which they arrive. The statistics for each queue are about 
the same.

# choke Q1 log
The results of this log are also as expected. Increasing the process time for
Q1 drastically inscreased the number of dropped packets, as Q1 is the main gateway
for all packets. Even if Q2 and Q3 had small process times, there were a large 
number of drops.

# choke Q2 log
The results of this log are again as expected. Choking either Q2 or Q3 doesn't
have a significant effect on the amount of dropped packets. This is because 
Q2 and Q3 only receive at most half of the packets that are not dropped. They
also have more time to process packets than Q1 as they only arive half as often.

