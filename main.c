#include <stdio.h>
#include "list.h"
#include "parser.h"
#include "processing.h"



int main(int c, char **argv){
	arguments(c, argv);
	if (get_unaccepted()){
		printf("I'm sorry but that input isn't accepted\n");
		return 1;
	}
	if (get_contain_p()){
		if(get_provided_pid()){
			int PID = get_pid();
			if (PID <= 0){
				printf("please provide a real PID, thank you\n");
				return 1;
			}
			printf("PID: %d ", PID);
			if (!get_not_contain_U()){
				printf("utime: %d ", stat_U(PID));
			}
			if (get_contain_s()){
				printf("State: %s ", stat_s(PID));
			}
			if (get_contain_S()){
				printf("stime: %d ", stat_S(PID));
			}
			if (get_contain_v()){
				printf("Size: %d ", stat_v(PID));
			}
			if (!get_not_contain_c()){
				printf("cmd: ");
				stat_c(PID);
			}
			printf("\n");
		}
		else{
			printf("Please provide a PID if you are going to use -p\n");
			return 1;
		}
	}
	
	//int *p = List("/proc");
	if (get_empty()){
		printf("test");
	}
	if (get_contain_p()){
		
	}

	
	
	/*
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
	* */

	
	

	return 0;
}
