/*
 * list.c
 * 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1000	

// Function declarations
void Search(int name);
int ScanFile();


static int id = -1;
static int match = 0;
static int userProc[BUFSIZE];

//probaby turn this into a header file, or function to a .h file
//tempory main
int main()
{
	DIR *dir = opendir("/proc");
	struct dirent* dirp;
	long pid;

	if(dir == NULL){
		printf("No directory found.\n");
		exit(1);
	}

	// Get user id
	id = getuid();
	
	// Iterate through /proc
	// Scan status file and match userID
	while((dirp = readdir(dir)) != NULL){
		if(!isdigit(*dirp->d_name))
			continue;
		
		// store all processes folders into char array
		pid = strtol(dirp->d_name, NULL, 10);
		// Check for user process
		Search(pid);
	}
	
	for(int i = 0; i < match; i++)
		printf("%d ", userProc[i]);
	printf("\n");

	closedir(dir);
	return 0;
}

/*
 * No return value
 * Instead iterates through the subdirectories of /proc and opens the status file.
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
	if(dp == NULL){
		printf("\nFailed to open subdirectory\n");
	}
	
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
}
