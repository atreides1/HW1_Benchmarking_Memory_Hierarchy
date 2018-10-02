# HW1_Benchmarking_Memory_Hierarchy
Homework assignment # 1 for CS 389 - Brought to you by Sierra Schlott and Mercy Bhakta

Important files: benchmark.cpp, mean adjusted scatter.PNG

Secondary files: full data scatter.PNG (3 trials plotted with both raw mean time and adjusted mean time), hw1_graph.gp (gnuplot file for full data), graphmedians.gp (gnuplot for mean adjusted scatter), test.csv (our raw data), medians.csv (medians of raw data points)

Part 1: Please see benchmark.cpp. The output produced is <buffer size (bytes)> <Raw Mean Time(ns)> <Adjusted Mean Time (ns)>

Part 2: See mean adjusted scatter.PNG. (We divided our buffer size in Bytes by 1024 to get a buffer size in KB for our x axis.)

Answers to Part 3: (Refering to sizes in KB rather than B for simplicity.)

  1) The L1 cache is at least 1 - 256 KB in size, since our adjusted mean time to read from a buffer of 1 KB is about 
    1 - 10 ns, after which the times increase to the next magnitude.
    The L2 cache size is in the range 512 - 2048 KB. When we read from a buffer of size 512 KB, our time doubled 
    and remained in the range 14 - 30 ns.
    The L3 cache size is in the range 2048 - 16384 KB. When reading a buffer of size 16384 KB, the time 
    more than doubled and then remained in the range 30 - 100 ns.
    When reading from a buffer size of 16384 KB and greater, the average time jumped to around 140 ns and remained above 100 ns 
    for the remaining buffer sizes average accesses. Since it's greater than the L3 cache, this implies the data is
    being stored and read from main memory.
    
   2) Our data did approximately match the numbers on the website. We had times that matched their values for a fetch
   from the L1 cache (2 ns), L2 cache (7 ns), and main memory (100 ns). Our data did however extend past this with a 
   range of 100 - 160 ns. 

  3) The computer we used has an Intel Core i7-6600u CPU. It has three cache sizes, with L1 having 128 KB, L2 having 512 KB, and L3 having 4MB.
    Our guesses were fairly accurate, with each cache size falling into the range we had specified. The actual size of
    L1 was in the middle of what we had guessed (128 KB), L2 starts at the range we had specified (512 KB), and the size for L3 (4 MB) fell within the range of our guess.


