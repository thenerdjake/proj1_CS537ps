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

int stat_U(int PID){
	
	
	sprintf(path, "/proc/%d/stat", PID);
	//printf("%s\n", path);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", str);
	//printf("%s\n", str);
	clock = atoi(str);
	//printf("%d\n", sysconf(_SC_CLK_TCK));
	//sec = clock / sysconf(_SC_CLK_TCK);
	//printf("%d\n", sec);
	return clock;
}

char* stat_s(int PID){
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	fscanf(fp, "%*s %*s %s", state);
	printf("%s\n", state);
	return state;
}

int stat_S(int PID){
	sprintf(path, "/proc/%d/stat", PID);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %s", str);
	clock = atoi(str);
	printf("%d\n", clock);
	return clock;
}

int stat_v(int PID){
	sprintf(path, "/proc/%d/statm", PID);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	fscanf(fp, "%s", str);
	size = atoi(str);
	return clock;
}

char* stat_c(int PID){
	sprintf(path, "/proc/%d/cmdline", PID);
	FILE* fp = fopen(path, "r");
	if (fp == NULL){
		//printf("error\n");
	}
	size_t length;
	char* buff;
	length = fread(cmd, sizeof(char), 100, fp);
	buff = cmd;
	while (buff < cmd + length){
		printf("%s ", buff);
		buff += strlen (buff) + 1;
	}
	return cmd;
}

int main(int argc, char **argv)
{
	int PID= 515;
	//printf("%d\n", PID);
	stat_c(PID);
	return 0;
}

