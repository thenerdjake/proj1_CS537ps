/*
 * parser.c
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"

char* state_info;
struct dirent *myFile;
const int path_size = BUFFER;
int clock;
char* time[BUFFER];
char path[BUFFER];
char str[BUFFER];
char state[1];
int size;
char cmd[BUFSIZE];

/*Takes int PID as filepath and returns 14th string from stat file
 * 
 * @param the PID to lookup
 * 
 * @return the utime of process matching PID
 */
int stat_U(int PID){
	//creating the path to stat with the given PID
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	//take the 14th string
	fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", str);
	//change the string to an int for export
	clock = atoi(str);
	//does not say to divide by clock so I commented out that
	//sec = clock / sysconf(_SC_CLK_TCK);
	return clock;
}

/*
 * Takes int PID as filepath and returns third string from stat file
 *
 * @param The PID to lookup
 *
 * @return Returns the state of process matching PID
 */
char* stat_s(int PID){
	//creating path to stat with given PID
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	//take the third string
	fscanf(fp, "%*s %*s %s", state);
	return state;
}

/*
 * Takes int PID as filepath and returns the "stime" of process
 *
 * @param The PID to lookup
 *
 * @return Returns the total system up time of process matching PID
 */
int stat_S(int PID){
	//creating path to stat with given PID
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	//take the 15th string
	fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", str);
	//change the string to int to output
	clock = atoi(str);
	return clock;
}

/*
 * Takes PID as filepath and returns vitual memory size of process
 *
 * @param The PID to lookup
 *
 * @return The vitual memory size of process matching PID
 */
int stat_v(int PID){
	//creating path to statm with given PID
	sprintf(path, "/proc/%d/statm", PID);
	FILE* fp = fopen(path, "r");
	//take the first string in statm
	fscanf(fp, "%s", str);
	//convert it to int
	size = atoi(str);
	return size;
}

/*
 * Takes PID as filepath and prints the command-line that started process
 *
 * @param The PID to lookup

 */
void stat_c(int PID){
	size_t length;
	char* buff;
	//creating path to cmdline with given PID
	sprintf(path, "/proc/%d/cmdline", PID);
	FILE* fp = fopen(path, "r");
	//read in to buffer from the file and output length
	length = fread(cmd, sizeof(char), 100, fp);
	buff = cmd;
	//copy that buffer
	while (buff < cmd + length){
		printf("%s ", buff);
		buff += strlen (buff) + 1;
	}
}

int exist_PID(int PID){
	sprintf(path, "/proc/%d", PID);
	if( access( path, F_OK ) != -1 ){
		return 1;
	}
	else{
		return 0;
	}
}
