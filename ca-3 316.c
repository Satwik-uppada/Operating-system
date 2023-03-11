// C implementation of First - Fit algorithm
#include<stdio.h>
#include <stdlib.h>
int allocated=0;
int wasted=0;
int externalFragmentation=0;

// Function to allocate memory to
// blocks as per First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n)
{

    int i, j;
    int allocation[n];
    int allocatedBlocks[m];
    int numAllocatedBlocks = 0;
    int numFreeBlocks = m;
    for(i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for(i = 0; i < m; i++)
    {
        allocatedBlocks[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (allocatedBlocks[j] == 0 && blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                allocated =allocated+processSize[i];
                blockSize[j]=blockSize[j]-processSize[i];
                if (blockSize[j] == 0)
                {
                    numAllocatedBlocks++;
                    numFreeBlocks--;
                    allocatedBlocks[j] = 1;
                } 
                break;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        if (allocatedBlocks[i] == 0)
        {
            wasted += blockSize[i];
        }
    }
    
    externalFragmentation = blockSize[0];
    for (i = 1; i < m; i++)
    {
        if (blockSize[i] > externalFragmentation)
        {
            externalFragmentation = blockSize[i];
        }
    }
    
    printf("\nProcess No.\t\tProcess Size\t\t\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t\t", i+1);
        printf("%i\t\t\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("\nTotal memory allocated: %i", allocated);
    printf("\nTotal memory wasted: %i", wasted);
    printf("\nExternal fragmentation: %i", externalFragmentation);
    printf("\nNumber of allocated blocks: %i", numAllocatedBlocks);
    printf("\nNumber of free blocks: %i", numFreeBlocks);
}


// Driver code
int main()
{
	int m; //number of blocks in the memory
	int n; //number of processes in the input queue
	int k1;
	int k2;
	printf("Enter no.of elements you want to enter in block size: ");
	scanf("%d",&k1);
	printf("Enter no.of elements you want to enter in process size: ");
	scanf("%d",&k2);

	if(k1<=0){
		printf("Invalid input for k1\n");
		exit(1);
	}
	if(k2<=0){
		printf("Invalid input for k2\n");
		exit(1);
	}
	int blockSize[k1];
	int processSize[k2];
	printf("Enter %d elements to add in block size array:\n", k1);
    for(int i = 0; i < k1; i++) {
        scanf("%d", &blockSize[i]); // Input each element and store in array
    }

    printf("The array elements in block size are:\n");
    for(int i = 0; i < k1; i++) {
        printf("%d ", blockSize[i]); // Print each element of the array
    }
    printf("\n");
    
     printf("Enter %d elements to add in process size:\n", k2);
    for(int i = 0; i < k2; i++) {
        scanf("%d", &processSize[i]); // Input each element and store in array
    }

    printf("The array elements in process size are:\n");
    for(int i = 0; i < k2; i++) {
        printf("%d ", processSize[i]); // Print each element of the array
    }
    printf("\n");
    
	m = sizeof(blockSize) / sizeof(blockSize[0]);
	n = sizeof(processSize) / sizeof(processSize[0]);


	firstFit(blockSize, m, processSize, n);

	return 0 ;
}
