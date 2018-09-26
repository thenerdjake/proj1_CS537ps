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
#include <string.h>

#define BUFSIZE 1000	

// Function declarations
char Search(int name);
int ScanFile();

//probaby turn this into a header file, or function to a .h file
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
	
	// TO DO
	// Iterate through /proc
	// Scan status file and match userID
	int subd[BUFSIZE];
	int index = 0;

	while((dirp = readdir(dir)) != NULL){
		if(!isdigit(*dirp->d_name))
			continue;
		
		// store all processes folders into char array
		pid = strtol(dirp->d_name, NULL, 10);
		subd[index] = pid;
		index++;

		printf("\nEntering Search()\n");
		char a = Search(pid);

		// This print is for testing purposes only
		printf("%li ", pid);
		if(index % 10 == 0){
			printf("\n");
		}
	}

	// check char array contents
	printf("\n-----------------------------------------------\n");
	for(int i = 0; i < index; i++){
			if(i%10 == 0 && i > 0)
				printf("\n");
			
			printf("%d ", subd[i]);
		}

	printf("\n");
	


	closedir(dir);
	return 0;
}

// Go through each /proc process subdirectory and open status file
char Search(int name){
	char path[256];
	char filepath[256];


	sprintf(path, "/proc/%d", name);
	
	// Code below needs debugging
	DIR *dp = opendir(path);
	if(dp == NULL){
		printf("\nFailed to open subdirectory\n");
	}

	struct dirent *ent;
	char word[1024];
	while((ent = readdir(dp)) != NULL){
		if(strcmp(ent->d_name, "status") == 0){
			// open the status file
			scanf(filepath, "/proc/%s/status", ent->d_name);
			FILE *fp = fopen(filepath, "r");
			// Scan file userID
			while(fscanf(fp, "%1023s", word)){
				puts(word);
			}
		}

	}

	closedir(dp);

	return 'a';
}

// Scan status file and match userID
//		Return:
//			0 - Different userID
//			1 - Same userID
int ScanFile(){
	return 0;
}
