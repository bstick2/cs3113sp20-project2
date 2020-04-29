#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function to allocate memory to blocks as per Best fit 
// algorithm 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
    // Stores block id of the block allocated to a 
    // process 
    int allocation[n]; 
  
    // Initially no block is assigned to any process 
    memset(allocation, -1, sizeof(allocation)); 
  
    // pick each process and find suitable blocks 
    // according to its size ad assign to it 
    for (int i=0; i<n; i++) 
    { 
        // Find the best fit block for current process 
        int bestIdx = -1; 
        for (int j=0; j<m; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                if (bestIdx == -1) 
                    bestIdx = j; 
                else if (blockSize[bestIdx] > blockSize[j]) 
                    bestIdx = j; 
            } 
        } 
  
        // If we could find a block for current process 
        if (bestIdx != -1) 
        { 
            // allocate block j to p[i] process 
            allocation[i] = bestIdx; 
  
            // Reduce available memory in this block. 
            blockSize[bestIdx] -= processSize[i]; 
        } 
    } 
  
    
} 

void Request()
{
    dprintf(STDOUT_FILENO, "Done");
}

void Release()
{
    dprintf(STDOUT_FILENO, "Done");
}

void ListAvailable()
{
    dprintf(STDOUT_FILENO, "Done");
}

void ListAssigned()
{
    dprintf(STDOUT_FILENO, "Done");
}

void Find()
{
    dprintf(STDOUT_FILENO, "Done");
}

int main()
{
    unsigned char instruction[14];
	unsigned char process[2];
	int bytes;
	unsigned char request[7] = {'R','E','Q','U','E','S','T'};
    unsigned char release[7] = {'R','E','L','E','A','S','E'};
    unsigned char listAvailable[14] = {'L','I','S','T',' ','A','V','A','I','L','A','B','L','E'};
    unsigned char listAssigned[13] = {'L','I','S','T',' ','A','S','S','I','G','N','E','D'};
    unsigned char find[4] = {'F','I','N','D'};
	LOOP:if(fgets(instruction, 14, stdin)){
		sscanf(instruction, "%s %s %d", instruction, process, &bytes);
   
    	if (instruction[0] == '#'){
      	  goto LOOP;
		}
    	else if (instruction[0] == 'R'){
        	if (instruction[2] == 'Q'){
            	Request();
				goto LOOP;
    		}
    		else if (instruction[2] == 'L'){
            	Release();
				goto LOOP;
    		}
    	}
    	else if (instruction[0] == 'L'){
        	if(instruction[5] == 'V'){
            	ListAvailable();
				goto LOOP;
        	}
        	else if(instruction[5] == 'S'){
            	ListAssigned();
				goto LOOP;
        	}
    	}
    	else if(instruction[0] == 'F'){
        	Find();
			goto LOOP;
    	}
	}
}