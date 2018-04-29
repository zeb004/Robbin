#include<stdio.h>
#include<stdbool.h>
void findWt(int processes[], int g, int burst[], int wait[], int quantum) {
    
    int bleft[g];
    for (int i = 0 ; i < g ; i++)
        bleft[i] =  burst[i];
 
    int time = 0;
    while (1) {
        bool done = true;
        for (int i = 0 ; i < g; i++) {
            if (bleft[i] > 0) {
                done = false;
 
            if (bleft[i] > quantum) {
                    time += quantum;
                    bleft[i] -= quantum;
                } 
            else {
                    time = time + bleft[i];
                    wait[i] = time - burst[i];
                    bleft[i] = 0;
                }
              }
          }

          if (done == true)
          break;
    }
}
 
void findTat(int processes[], int g, int burst[], int wait[], int total[]) {
    for (int i = 0; i < g ; i++)
        total[i] = burst[i] + wait[i];
}
 
void findtime(int processes[], int g, int burst[],int quantum) {
int totalw=0;
int wait[g];
int totalt=0;
int total[g];
    findWt(processes, g, burst, wait, quantum);
    findTat(processes, g, burst, wait, total);
    printf("Processes \t Burst time \t Waiting time \t Turn around time\n");
    for (int i=0; i<g; i++) {
        totalw = totalw + wait[i];
        totalt = totalt + total[i];
printf("%d \t\t %d\t\t %d\t \t%d\n", i+1, burst[i],wait[i],total[i]);
        
    }
 
    printf("Average waiting time = %f",((float)totalw / (float)g));
    printf( "\nAverage turn around time = %f",((float)totalt / (float)g));
}

int main() {
	int arrival=0;
	int priorityT=0;
	int burst=0;
	//open file
	static const char filename[] = "input.txt";
	FILE * fp;
	int line;
	fp=fopen(filename,"r");
	int oneline=1;
	int k;
	//read the first line of input file to get number of processes
		while(oneline!=0) {
		fscanf(fp,"%d",&line);
		k=line;
		oneline--;
		}
	int processes[k];
	int burstT[k];
	int arrivaltime[k];
	int priority[k];
    //get num processes
	printf("%d\t Processes\n",k);
  	//label processes
	for(int y=0;y<k;y++) {
    		processes[y]=y+1;
	}
    int n = sizeof processes / sizeof processes[0];
 
    // get burst times
	for(int w=0;w<k;w++) {
	fscanf(fp, "%d" "%d" "%d", &arrival, &priorityT,&burst);
	arrivaltime[w]=arrival;
	priority[w]=priorityT;
	burstT[w]=burst;
	}
    
 
    // Time quantum
    int quantum;
	printf("Enter Quantum:");
	scanf("%d",&quantum);
    findtime(processes, n, burstT, quantum);
    return 0;
}
 
