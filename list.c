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
int id = -1;
int match = 0;
int userProc[BUFSIZE];

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
	id = getuid();
	printf("\n%d\n", id);
	
	// TO DO
	// Iterate through /proc
	// Scan status file and match userID
	//int subd[BUFSIZE];
	int index = 0;

	while((dirp = readdir(dir)) != NULL){
		if(!isdigit(*dirp->d_name))
			continue;
		
		// store all processes folders into char array
		pid = strtol(dirp->d_name, NULL, 10);
	//	subd[index] = pid;
		index++;

		printf("\nEntering Search()\n");
		char a = Search(pid);

		// This print is for testing purposes only
//		printf("%li ", pid);
//		if(index % 10 == 0){
//			printf("\n");
//		}
	}
//
//	// check char array contents
////	printf("\n-----------------------------------------------\n");
//	for(int i = 0; i < index; i++){
//			if(i%10 == 0 && i > 0)
//				printf("\n");
//			
//			printf("%d ", subd[i]);
//		}
//
//	printf("\n");
	
	printf("%d\n", match);

	for(int i = 0; i < match; i++)
		printf("%d ", userProc[i]);

	printf("\n");

	closedir(dir);
	return 0;
}

// Go through each /proc process subdirectory and open status file
char Search(int name){
	char path[256];
	//char filepath[256];

	sprintf(path, "/proc/%d", name);

	// Code below needs debugging
	DIR *dp = opendir("/proc/1");
	if(dp == NULL){
		printf("\nFailed to open subdirectory\n");
	}
	
	struct dirent *ent;
	char word[1024];
	while((ent = readdir(dp)) != NULL){

		if(strcmp(ent->d_name, "status") == 0){
			// open the status file
			strcat(path, "/status");

			FILE *fp = fopen(path, "r");
			if(fp == NULL){
				printf("\nFailed to open file\n");
				exit(1);
			}
			// Scan file userID
			int num1 = -1;
			while(fscanf(fp, "%1023s", word) == 1) {
				if(strcmp(word, "Uid:") == 0){
					fscanf(fp, "%d", &num1);
					printf("%d\n", num1);
					
					if(num1 == id){
						userProc[match] = name;
						match++;
					}
				}
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
