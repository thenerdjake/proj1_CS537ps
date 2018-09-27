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

char* state_info;
struct dirent *myFile;
const int path_size = 80;
int sec;
int min;
int hour;
int clock;
char* time[80];
char path[80];
char str[80];
char state[1];
int size;
char cmd[1000];

//the U option
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

char* stat_s(int PID){
	//creating path to stat with given PID
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	//take the third string
	fscanf(fp, "%*s %*s %s", state);
	return state;
}

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

int stat_v(int PID){
	//creating path to statm with given PID
	sprintf(path, "/proc/%d/statm", PID);
	FILE* fp = fopen(path, "r");
	//take the first string in statm
	fscanf(fp, "%s", str);
	//convert it to int
	size = atoi(str);
	return clock;
}

char* stat_c(int PID){
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
	return cmd;
}

//testing main
int main(int argc, char **argv)
{
	int PID= 515;
	stat_c(PID);
	return 0;
}

