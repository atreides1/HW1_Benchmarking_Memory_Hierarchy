# HW1_Benchmarking_Memory_Hierarchy
Homework assignment # 1 for CS 389 - Brought to you by Sierra Schlott and Mercy Bhakta

Important files: 

Answers to Part 3:

  1) The L1 cache is at least 1024 Bytes in size, since our average time to read from a buffer of 1024 Bytes is about 
    0.5 - 1 ns, the time it would take to read data stored in the L1 cache.
    The L2 cache size is in the range 2048 - 131072 Bytes. When we read from a buffer of size 2048, our time doubled 
    and remained in the range 2-7 ns.
    The L3 cache size is in the range 262144 - 2097152 Bytes. When reading a buffer of size 262144 Bytes, the time 
    more than doubled to be in the range 32-68 ns.
    When reading from a buffer size of 4194304 Bytes, the average time jumped to around 135 ns and remained above 100 ns 
    for the remaining buffer sizes' average accesses. Since it's greater than the L3 cache, this implies the data is
    being stored and read from main memory.
    
   2) Our data did approximately match the numbers on the website. We had times that matched their values for a fetch
   from the L1 cache (0.5 ns), L2 cache (7 ns), and main memory (100 ns). Our data did however extend past this with a 
   range of 100 - 160 ns. 

  3) My computer is a Intel i3 7100h. It has three cache sizes, with L1 having 128 KB, L2 having 512 KB, and L3 having 3MB.
    Our guesses were ...


