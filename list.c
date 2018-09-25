/*
 * list.c
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

//tempory main
int main()
{
	DIR *dir = opendir("/proc");
	struct dirent* dirp;
	long pid;

	if(dir == NULL){
		printf("No directory found.\n");
		exit(0);
	}


	
	// Get user id
	int id = getuid();
	printf("\n%d\n", id);
	
	// Iterate through /proc
	
	int count = 0;
	while((dirp = readdir(dir)) != NULL){
		if(!isdigit(*dirp->d_name))
			continue;
		

		pid = strtol(dirp->d_name, NULL, 10);
		printf("%li ", pid);
		if(count == 20){
			printf("\n");
			count = 0;
		}
		count++;
	}
	


	closedir(dir);
	return 0;
}
