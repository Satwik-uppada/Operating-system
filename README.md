# Operating-system
This program is to impliment first-fit simulation of a memory management<br>
# outputs of this program
1.Number of blocks allocated<br>
2.Number of blocks wasted<br>
3.Total memory allocated to the blocks<br>
4.Table of remaining memory after allocation of processes<br>
5.Total Fragmentation<br>
6.Average Fragmentation<br>
# Description<hr><br>
This program implements the <font color="red">'First fit'</font> memory management algorithm to allocate memory blocks to processes. The user inputs the number and size of processes and the number and size of memory blocks. The program then executes the first fit algorithm and displays the allocation table, allocated and unused blocks, allocated memory size, remaining memory for each block, total fragmentation, and average fragmentation. <br>


The main function initializes arrays, inputs values from users, executes the first fit algorithm, and calls several functions to display blocks allocated, wasted blocks, allocated memory size, remaining memory, and fragmentation. <br>


1.The firstFit() function implements the algorithm by taking the size of each process and finding the first block that can accommodate it.<br> 
2.The display_Allocation_Table() function displays a table of each process, its size, and the block it allocated or marked as not allocated. <br>
3.The display_Allocated_Blocks() function counts the number of blocks that have been allocated, while calculate_Wasted_Blocks() counts unused blocks. <br>
4.The displayRemainingMemory() function displays the remaining memory for each block.<br>
5.The program uses calculate_Fragmentation() to calculate the total fragmentation of the memory blocks, and calculate_Average_of_Fragmentation() to calculate the average fragmentation per process.<br>
