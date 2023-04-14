
#include <stdio.h>
#include <string.h>



void firstFit(int process_size[], int n, int block_size[], int m);
void display_Allocation_Table(int process_size[], int allocation[], int n) ;
void display_Allocated_Blocks(int allocation[], int m) ; 
int  calculate_Wasted_Blocks(int allocation[], int m);
int display_Allocated_MemorySize(int process_size[], int n) ;
void displayRemainingMemory(int block_size[], int m);
float  calculate_Fragmentation(int block_size[], int m,int destArray[]);
float calculate_Average_of_Fragmentation(int total_fragmentation, int n);



int allocation[100]; // i set default allocation size as 100



// main function
int main() {

    printf("*********** Welcome to First-Fit Memory Management Algorithm **********");
    int n, m; // intializing n and m
    printf("\nEnter the number of processes: ");
    scanf("%d", &n); // Taking user input for no.of processes user want to add
    int process_size[n]; // intitalizing process_size array with length n

    // Taking user input of process sizes with n iterations
    for (int i = 0; i < n; i++) {
        printf("Enter the size of process %d: ", i+1);
        scanf("%d", &process_size[i]);
    }

    printf("\n\nEnter the number of blocks: ");
    scanf("%d", &m); // Taking input for no.of blocks user want to add
    int block_size[m];  // intitalizing block_size array with length m

     // Taking user input of block sizes with m iterations
    for (int i = 0; i < m; i++) {
        printf("Enter the size of block %d: ", i+1);
        scanf("%d", &block_size[i]);
    }
    
    // basic inputs for testing the code 

    //  int process_size[] = {212, 426, 112, 496};  // Process sizes
    // int block_size[] = {100, 500, 200, 300, 600};  // Block sizes
    // int n = sizeof(process_size) / sizeof(process_size[0]);  // Number of processes
    // int m = sizeof(block_size) / sizeof(block_size[0]);  // Number of blocks

    int destArray[m]; // a temperary array for storing intial block sizes

    // adding elements of block size array to destArray by iterating each element
    for (int i = 0; i < m; i++) {
       destArray[i] = block_size[i];
    }
    

    printf("\n\n-------------------------------------Memory Management Algorithm----------------------------------------------");
    
    // memset is a library function in C programming language that sets a block of memory to a specific value.
    // It takes three arguments - a pointer to the starting address of the memory to be filled, the value to be set,
    // and the number of bytes to be filled with the value
    memset(allocation, -1, sizeof(allocation));  // Initialize allocation array to -1

    firstFit(process_size, n, block_size, m);  // Run First Fit algorithm

    display_Allocation_Table(process_size, allocation, n); // display allocation table

    display_Allocated_Blocks(allocation, m);  // Display number of allocated blocks

    int wasted_blocks = calculate_Wasted_Blocks(allocation, m);  // Calculate wasted blocks
    printf("Number of wasted blocks: %d\n", wasted_blocks);

    int allocated_memory=display_Allocated_MemorySize(process_size, n);  // return total memory  allocated to blocks
    printf("Allocated memory: %d\n",allocated_memory);
    
    displayRemainingMemory(block_size, m);      // display remaining memory after allocation of the processes

    float total_fragmentation=calculate_Fragmentation(block_size,m,destArray);  // calculate fragmentation 
    printf("Total Fragmentation: %.2f\n",total_fragmentation);
    
    
    float avg_fragmentation = calculate_Average_of_Fragmentation(total_fragmentation, n);  // Calculate average fragmentation
    printf("Average fragmentation: %.2f\n", avg_fragmentation);
    
    return 0;
}


//function implements the first-fit algorithm
void firstFit(int process_size[], int n, int block_size[], int m){
    memset(allocation, -1, sizeof(allocation)); // Initialize allocation array to -1
  // initially assigning -1 to all allocation indexes
  // means nothing is allocated currently
  for(int i = 0; i < n; i++)
  {
	allocation[i] = -1;
  }
 
  // take each process one by one and find
  // first block that can accomodate it
  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j <m; j++) { 
          if (block_size[j] >= process_size[i])
          {
              // allocate block j to p[i] process
              allocation[i] = j;
              // Reduce size of block j as it has acc
              block_size[j] -= process_size[i];
              break;
          }
      }
                                        
    }
}

// displays the allocation table in a tabular form with columns 
//for process number, process size, and allocated block number.
void display_Allocation_Table(int process_size[], int allocation[], int n) {

  printf("\n\n");
printf("+--------------------------------------------------------------+\n");
printf("|Process No.\t\tProcess Size\tAllocated Block no.    |\n");
printf("+--------------------------------------------------------------+\n");
for (int i = 0; i < n; i++)
{
    printf("| %i\t\t\t", i+1);
    printf("%i\t\t\t", process_size[i]);
    if (allocation[i] != -1)
        printf("%i \t       |", allocation[i] + 1);
    else
        printf("Not Allocated  |");
    printf("\n");
    printf("+--------------------------------------------------------------+\n");
}
}


//calculates and returns the total memory allocated to the processes.
int display_Allocated_MemorySize(int process_size[], int n) {
    int total_allocated_memory = 0;
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {  // If process is allocated
            total_allocated_memory += process_size[i];
        }
    }
   
   return total_allocated_memory;
}


// calculates and displays the number of allocated blocks.
void display_Allocated_Blocks(int allocation[], int m) {
    int num_allocated = 0;
    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1) {
            num_allocated++;
        }
    }
    printf("Allocated_blocks: %d\n",num_allocated);
}


// calculates and returns the number of wasted (unallocated) blocks after the allocation is done.
int calculate_Wasted_Blocks(int allocation[], int m) {
    int wasted_blocks = 0;
    for (int i = 0; i < m; i++) {  // For each memory block
        if (allocation[i] == -1) {  // If block is not allocated
            wasted_blocks++;
        }
    }
    return wasted_blocks;
}

// displays the remaining memory(blocksizes) after allocation for each block.
void displayRemainingMemory(int block_size[], int m) {
    printf("\nBlock No.    Remaining memory after allocation\n\n");
    for (int i = 0; i < m; i++) {
        printf("   %d\t\t\t    %d\n", i+1, block_size[i]);
    }
    
}


// calculates and returns the total fragmentation of the blocks.
float calculate_Fragmentation(int block_size[],int m,int destArray[]) {
    int total_fragmentation = 0;
      for(int i=0;i<m;i++){
        if(block_size[i] != destArray[i]){
             total_fragmentation += block_size[i];
        }
      }

    return total_fragmentation;
}


// calculates and returns the average fragmentation of the blocks.
float calculate_Average_of_Fragmentation(int total_fragmentation, int n) {
    
   return (float)total_fragmentation/n*100;
}

/*Average Fragementation= total fragmentation divided by no.of processes * 100 */
