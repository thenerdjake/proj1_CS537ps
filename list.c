/*
 * list.c
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "list.h"

// Globals
static int id = -1;
static int match = 0;
static int userProc[BUFSIZE];

/*
 * Opens a directory and iterates through it. 
 * Returns an integer pointer.
 *
 * @param Takes in directory name to be opened
 *
 * @return The address location of an int array
 */
int* List(char *str)
{
	DIR *dir = opendir(str);
	if(dir){
		struct dirent* dirp;
		long pid;

		// Get user id
		id = getuid();

		// Iterate through /proc
		// Scan status file and match userID
		while((dirp = readdir(dir)) != NULL){
			if(!isdigit(*dirp->d_name))
				continue;

			// Store all processes folders into char array
			pid = strtol(dirp->d_name, NULL, 10);
			// Check for user process
			Search(pid);
		}

		int *list = userProc;
		closedir(dir);
		return list;
	} else if(errno == ENOENT)
		puts("No entry of this directory.");
	else if(errno == ENOTDIR)
		puts("Not a directory.");
	else if(errno == EACCES)
		puts("Permission denied to access this directory");
	else
		puts("New error, check the manual.");
	exit(1);
}

/*
 * Iterates through the subdirectories of /proc and opens the status file.
 * Checks the userID line within the status file and matches it to current user
 * ID.  Adds the processNum to an array if userID and ID match.
 *
 * @param processNum Takes the name of the subdirectory to be opened
 */
void Search(int processNum){
	char path[256];
	FILE *fp = NULL;
	char word[1024];
	struct dirent *ent;
	int num = -1;

	// Append process number to filepath 
	sprintf(path, "/proc/%d", processNum);

	// Open subdirectory and find status file
	DIR *dp = opendir("/proc/1");
	if(dp){
		// Iterate through subdirectory
		while((ent = readdir(dp)) != NULL){
			// Check if on status file
			if(strcmp(ent->d_name, "status") == 0){
				// Create file path name to open status file
				strcat(path, "/status");
				fp = fopen(path, "r");
				if(fp == NULL){
					printf("\nFailed to open file\n");
					exit(1);
				}
				// Scan file userID
				while(fscanf(fp, "%1023s", word) == 1) {
					if(strcmp(word, "Uid:") == 0){
						fscanf(fp, "%d", &num);
						// If user process, add to array
						if(num == id){
							userProc[match] = processNum;
							match++;
						}
					}
				}
			}
		}
		fclose(fp);
		closedir(dp);

	} else if(errno == ENOENT){
		puts("No entry of this directory.");
		exit(1);
	}
	else if(errno == ENOTDIR){
		puts("Not a directory.");
		exit(1);
	}
	else if(errno == EACCES){
		puts("Permission denied to access this directory");
		exit(1);
	}
	else{
		puts("New error, check the manual.");
		exit(1);
	}
}

/*
 * @return Returns the size of userProc
 */
int Size(){
	return match;
}
