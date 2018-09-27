#include <stdio.h>
#include "list.h"
#include "parser.h"

int main(int c, char **argv){
	int *p = List("/proc");
	
	// Test functions
	// print user processes
	for(int i = 0; i < Size(); i++){
		printf("PID: %-12d ", *(p + i));
		printf("utime: %-12d ", stat_U(*(p+i)));
		printf("State: %-12s ", stat_s(*(p+i)));
		printf("stime: %-12d ", stat_S(*(p+i)));
		printf("Size: %-12d ", stat_v(*(p+i)));
		printf("cmd: ");
		stat_c(*(p+i));
		printf("\n");

	}
	printf("\n");	

	
	

	return 0;
}
